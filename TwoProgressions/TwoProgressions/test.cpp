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
            int d = p[j] - p[i];  // ���㹫��
            if (d <= 0) continue;  // �������Ϊ��

            vector<int> first_seq;
            int count = 0;
            vector<int> visited(n, 0); // ��¼Ԫ���Ƿ��ѱ�����

            // ���ɵȲ�����
            for (int k = 0; k < n; ++k) {
                int expected_value = p[i] + count * d;
                if (count_map.find(expected_value) != count_map.end() && visited[k] < count_map[expected_value]) {
                    first_seq.push_back(expected_value);
                    count++;
                    visited[k]++; // ��¼��Ԫ���ѱ�ʹ��
                }
            }

            // ���ʣ��Ԫ���Ƿ��ܹ��ɵȲ�����
            vector<int> second_seq;
            for (int k = 0; k < n; ++k) {
                if (visited[k] < count_map[p[k]]) {
                    second_seq.push_back(p[k]); // ���ʣ��Ԫ��
                }
            }

            // ���ʣ��Ԫ�ؿ��Թ��ɵȲ�����
            if (is_arithmetic_progression(second_seq)) {
                // ���½�������ȿ������С�Ĺ���ͳ���
                if (count > l ||
                    (count == l && (f == -1 || p[i] < f ||
                        (p[i] == f && d < r) ||
                        (p[i] == f && d == r && count > l)))) {
                    f = p[i];  // ����
                    r = d;     // ����
                    l = count; // ����
                }
            }
        }
    }

    // ���ݳ���������
    if (l > 1) {
        result = to_string(f) + " " + to_string(r) + " " + to_string(l);
    }
    else {
        result = "-1";
    }
}

int main() {
    int T, N, ele;
    cin >> T; // ��ȡ������������
    vector<string> results(T); // �洢���н��

    for (int i = 0; i < T; i++) {
        cin >> N; // ��ȡÿ���������������鳤��
        vector<int> progression(N); // ��ȷ��ʼ����СΪ N
        for (int j = 0; j < N; j++) {
            cin >> progression[j]; // ֱ�����
        }
        solve(progression, results[i]); // ����ǰ��������
    }

    // һ����������н��
    for (const auto& res : results) {
        cout << res << endl;
    }

    return 0;
}
