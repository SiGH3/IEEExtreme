#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005; // 数组的最大长度

int n; // 数组的长度
int v[MAX_N]; // 存储输入数组
bool marked[MAX_N]; // 用于标记已属于第一个等差数列的元素
vector<vector<int>> solutions; // 用于存储符合条件的解

// 读取输入数据并初始化
void read() {
    solutions.clear(); // 清空之前的解
    memset(marked, 0, sizeof(marked)); // 初始化标记数组
    memset(v, 0, sizeof(v)); // 初始化输入数组
    cin >> n; // 输入数组长度
    for (int i = 0; i < n; ++i)
        cin >> v[i]; // 输入数组内容
}

// 判断给定数组是否为等差数列
bool is_progression(vector<int>& v) {
    if (v.size() < 2) return false; // 数组长度小于2无法构成等差数列
    int ratio = v[1] - v[0]; // 计算公差
    if (ratio == 0) { // 公差为0时不符合条件
        return false;
    }

    // 验证所有相邻项差值是否与公差相等
    for (int i = 0; i + 1 < v.size(); ++i)
        if (v[i] + ratio != v[i + 1])
            return false;
    return true;
}

// 尝试在数组中找到从first_idx开始，公差为ratio的等差数列
void check_progression(int first_idx, int ratio, int last_idx) {
    if (ratio == 0) { // 公差为0时直接返回
        return;
    }
    memset(marked, false, sizeof(marked)); // 清空标记数组
    int value = v[first_idx]; // 初始化当前等差数列的起始值
    int progression_size = 0; // 记录等差数列的长度

    // 找出符合等差条件的第一个数列并标记
    for (int i = 0; i <= last_idx; i += 1) {
        if (v[i] == value) { // 找到符合条件的数
            marked[i] = true; // 标记该位置
            value += ratio; // 更新下一个目标值
            ++progression_size; // 增加等差数列的长度
        }
    }

    if (!marked[last_idx]) // 若最后一个索引未标记，返回
        return;

    vector<int> second_progression;
    for (int i = 0; i < n; ++i) // 将未标记的元素构成第二个数列
        if (!marked[i])
            second_progression.push_back(v[i]);
    if (!is_progression(second_progression)) // 检查第二个数列是否为等差数列
        return;

    // 若找到两个符合条件的等差数列，将其信息存入solutions
    if (first_idx == 0)
        solutions.push_back(vector<int>({ v[first_idx], ratio, progression_size, 
                                         second_progression[0], second_progression[1] - second_progression[0], (int)second_progression.size() }));
    else
        solutions.push_back(vector<int>({ second_progression[0], second_progression[1] - second_progression[0], (int)second_progression.size(),
                                          v[first_idx], ratio, progression_size }));
}

// 处理数组长度为4的特殊情况
void special_case() {
    int ratio = v[n - 1] - v[n - 2]; // 计算最后两个元素的差值作为公差
    int i;

    // 从数组倒数第二个元素向前检查
    for (i = n - 2; i >= 2; --i)
        if (v[i] != v[n - 1] - ratio * (n - 1 - i)) { // 判断前面的数是否符合该等差
            check_progression(0, v[1] - v[0], i); // 尝试找出符合条件的等差数列
            return;
        }
}

// 尝试找出数组中两个符合条件的等差数列并输出结果
void solve() {
    if (n == 4) { // 数组长度为4时的特殊处理
        if (v[0] != v[1] and v[2] != v[3]) {
            cout << v[0] << " " << v[1] - v[0] << " 2 ";
            return;
        }

        if (v[0] != v[2] and v[1] != v[3]) {
            cout << v[0] << " " << v[2] - v[0] << " 2 ";
            return;
        }
        if (v[0] != v[3] and v[1] != v[2]) {
            cout << v[0] << " " << v[3] - v[0] << " 2 ";
            return;
        }

        cout << "-1\n";
        return;
    }

    // 遍历若干组合，尝试找出符合条件的等差数列对
    for (int second_idx = 1; second_idx <= 2; ++second_idx)
        for (int last_idx = n - 2; last_idx < n; ++last_idx)
            check_progression(0, v[second_idx] - v[0], last_idx);
    // check_progression(0, v[1] - v[0], n - 2);
    // check_progression(0, v[1] - v[0], n - 1);
    // check_progression(0, v[2] - v[0], n - 2);
    // check_progression(0, v[2] - v[0], n - 1);

    // 检查不同起点和公差组合是否符合要求
    
    check_progression(1, v[2] - v[1], n - 1);
    check_progression(1, v[2] - v[1], n - 2);

    check_progression(0, v[n - 1] - v[n - 2], n - 1);
    check_progression(1, v[n - 1] - v[n - 2], n - 1);
    check_progression(2, v[n - 1] - v[n - 2], n - 1);
    special_case();

    // 按字典序排列找到的解并输出字典序最小的解
    sort(solutions.begin(), solutions.end());
    if (solutions.size() == 0) {
        cout << "-1\n";
    }
    else {
        for (int i = 0; i < 3; ++i)
            cout << solutions[0][i] << " ";
    }
    cout << '\n';
}

int main() {
    int t; cin >> t; // 读取测试用例数
    while (t--) { // 对每个测试用例执行一次
        read(); // 读取数据
        solve(); // 解决当前测试用例
    }
    return 0;
}
