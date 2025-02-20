#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// ��ȡ��������
int get_number() {
    int num;
    cin >> num;
    return num;
}

int main()
{
    // ��ȡNֵ
    int N = get_number();

    // ��ȡ�����б�
    vector<int> nums(N);
    for (int i = 0; i < N; i++) 
    {
        nums[i] = get_number();
    }

    // ʹ��˫�˶��н��д���
    deque<int> q;
    q.push_back(nums[0]);

    for (int i = 1; i < N; i++) 
    {
        int num = nums[i];
        if (q.back() <= num) 
        {
            q.push_back(num);  // �����ǰ���ֱȶ��е����һ�������ȣ�ֱ�Ӽ������
        }
        else 
        {
            int m = q.back();  // ����������һ��Ԫ��
            q.pop_back();  // �����������һ��Ԫ��
            // �������д��ڵ�ǰ���ֵ�Ԫ��
            while (!q.empty() && q.back() > num) 
            {
                q.pop_back();
            }
            q.push_back(m);  // �ӻ�ԭ����Ԫ��
        }
    }

    // �����Ч������������
    cout << q.size() << endl;

    return 0;
}
