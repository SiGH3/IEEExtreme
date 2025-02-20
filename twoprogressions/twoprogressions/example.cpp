#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005; // �������󳤶�

int n; // ����ĳ���
int v[MAX_N]; // �洢��������
bool marked[MAX_N]; // ���ڱ�������ڵ�һ���Ȳ����е�Ԫ��
vector<vector<int>> solutions; // ���ڴ洢���������Ľ�

// ��ȡ�������ݲ���ʼ��
void read() {
    solutions.clear(); // ���֮ǰ�Ľ�
    memset(marked, 0, sizeof(marked)); // ��ʼ���������
    memset(v, 0, sizeof(v)); // ��ʼ����������
    cin >> n; // �������鳤��
    for (int i = 0; i < n; ++i)
        cin >> v[i]; // ������������
}

// �жϸ��������Ƿ�Ϊ�Ȳ�����
bool is_progression(vector<int>& v) {
    if (v.size() < 2) return false; // ���鳤��С��2�޷����ɵȲ�����
    int ratio = v[1] - v[0]; // ���㹫��
    if (ratio == 0) { // ����Ϊ0ʱ����������
        return false;
    }

    // ��֤�����������ֵ�Ƿ��빫�����
    for (int i = 0; i + 1 < v.size(); ++i)
        if (v[i] + ratio != v[i + 1])
            return false;
    return true;
}

// �������������ҵ���first_idx��ʼ������Ϊratio�ĵȲ�����
void check_progression(int first_idx, int ratio, int last_idx) {
    if (ratio == 0) { // ����Ϊ0ʱֱ�ӷ���
        return;
    }
    memset(marked, false, sizeof(marked)); // ��ձ������
    int value = v[first_idx]; // ��ʼ����ǰ�Ȳ����е���ʼֵ
    int progression_size = 0; // ��¼�Ȳ����еĳ���

    // �ҳ����ϵȲ������ĵ�һ�����в����
    for (int i = 0; i <= last_idx; i += 1) {
        if (v[i] == value) { // �ҵ�������������
            marked[i] = true; // ��Ǹ�λ��
            value += ratio; // ������һ��Ŀ��ֵ
            ++progression_size; // ���ӵȲ����еĳ���
        }
    }

    if (!marked[last_idx]) // �����һ������δ��ǣ�����
        return;

    vector<int> second_progression;
    for (int i = 0; i < n; ++i) // ��δ��ǵ�Ԫ�ع��ɵڶ�������
        if (!marked[i])
            second_progression.push_back(v[i]);
    if (!is_progression(second_progression)) // ���ڶ��������Ƿ�Ϊ�Ȳ�����
        return;

    // ���ҵ��������������ĵȲ����У�������Ϣ����solutions
    if (first_idx == 0)
        solutions.push_back(vector<int>({ v[first_idx], ratio, progression_size, 
                                         second_progression[0], second_progression[1] - second_progression[0], (int)second_progression.size() }));
    else
        solutions.push_back(vector<int>({ second_progression[0], second_progression[1] - second_progression[0], (int)second_progression.size(),
                                          v[first_idx], ratio, progression_size }));
}

// �������鳤��Ϊ4���������
void special_case() {
    int ratio = v[n - 1] - v[n - 2]; // �����������Ԫ�صĲ�ֵ��Ϊ����
    int i;

    // �����鵹���ڶ���Ԫ����ǰ���
    for (i = n - 2; i >= 2; --i)
        if (v[i] != v[n - 1] - ratio * (n - 1 - i)) { // �ж�ǰ������Ƿ���ϸõȲ�
            check_progression(0, v[1] - v[0], i); // �����ҳ����������ĵȲ�����
            return;
        }
}

// �����ҳ��������������������ĵȲ����в�������
void solve() {
    if (n == 4) { // ���鳤��Ϊ4ʱ�����⴦��
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

    // ����������ϣ������ҳ����������ĵȲ����ж�
    for (int second_idx = 1; second_idx <= 2; ++second_idx)
        for (int last_idx = n - 2; last_idx < n; ++last_idx)
            check_progression(0, v[second_idx] - v[0], last_idx);
    // check_progression(0, v[1] - v[0], n - 2);
    // check_progression(0, v[1] - v[0], n - 1);
    // check_progression(0, v[2] - v[0], n - 2);
    // check_progression(0, v[2] - v[0], n - 1);

    // ��鲻ͬ���͹�������Ƿ����Ҫ��
    
    check_progression(1, v[2] - v[1], n - 1);
    check_progression(1, v[2] - v[1], n - 2);

    check_progression(0, v[n - 1] - v[n - 2], n - 1);
    check_progression(1, v[n - 1] - v[n - 2], n - 1);
    check_progression(2, v[n - 1] - v[n - 2], n - 1);
    special_case();

    // ���ֵ��������ҵ��ĽⲢ����ֵ�����С�Ľ�
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
    int t; cin >> t; // ��ȡ����������
    while (t--) { // ��ÿ����������ִ��һ��
        read(); // ��ȡ����
        solve(); // �����ǰ��������
    }
    return 0;
}
