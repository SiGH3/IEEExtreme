#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool is_arithmetic_progression(const vector<int>& seq) {
    if (seq.size() < 2) {
        return false;
    }
    int d = seq[1] - seq[0];
    for (size_t i = 1; i < seq.size(); ++i) {
        if (seq[i] - seq[i - 1] != d) {
            return false;
        }
    }
    return true;
}

void solve(vector<int>& p, string& result) {
    int f = -1, r = -1, l = -1;
    int n = p.size();

    if (n < 2) {
        result = "-1";
        return;
    }

    unordered_map<int, int> count_map;
    for (int num : p) {
        count_map[num]++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = p[j] - p[i];  // 计算公差
            if (d <= 0) continue;  // 公差必须为正

            vector<int> first_seq;
            int count = 0;
            vector<int> visited(n, 0); // 记录元素是否已被计入

            // 生成等差数列
            for (int k = 0; k < n; ++k) {
                int expected_value = p[i] + count * d;
                if (count_map.find(expected_value) != count_map.end() && visited[k] < count_map[expected_value]) {
                    first_seq.push_back(expected_value);
                    count++;
                    visited[k]++; // 记录该元素已被使用
                }
            }

            // 检查剩余元素是否能构成等差数列
            vector<int> second_seq;
            for (int k = 0; k < n; ++k) {
                if (visited[k] < count_map[p[k]]) {
                    second_seq.push_back(p[k]); // 添加剩余元素
                }
            }

            // 如果剩余元素可以构成等差数列
            if (is_arithmetic_progression(second_seq)) {
                // 更新结果：优先考虑首项、小的公差和长度
                if (count > l ||
                    (count == l && (f == -1 || p[i] < f ||
                        (p[i] == f && d < r) ||
                        (p[i] == f && d == r && count > l)))) {
                    f = p[i];  // 首项
                    r = d;     // 公差
                    l = count; // 长度
                }
            }
        }
    }

    // 根据长度输出结果
    if (l > 1) {
        result = to_string(f) + " " + to_string(r) + " " + to_string(l);
    }
    else {
        result = "-1";
    }
}

int main() {
    int T, N, ele;
    cin >> T; // 读取测试用例数量
    vector<string> results(T); // 存储所有结果

    for (int i = 0; i < T; i++) {
        cin >> N; // 读取每个测试用例的数组长度
        vector<int> progression(N); // 正确初始化大小为 N
        for (int j = 0; j < N; j++) {
            cin >> progression[j]; // 直接填充
        }
        solve(progression, results[i]); // 处理当前测试用例
    }

    // 一次性输出所有结果
    for (const auto& res : results) {
        cout << res << endl;
    }

    return 0;
}
