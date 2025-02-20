#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    long long n;
    cin >> n;
    vector<long long> a;
    long long b, ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++)  
    {
        cin >> b;
        if (b > 0)  //�Ȱ���������������
        {
            ans1 += b, ans2 += b;
        }
        else a.push_back(b);   //��������a��
    }

    sort(a.begin(), a.end(), greater<int>());  //�������������У�����С����󣬼�����ٸ����ĵ���ฺ���ģ���

    if (a.size() == n)   //���ȫ�Ǹ������������ٸ�����ฺ˳�������
    {
        ans1 += a[0];
        ans2 += a[0];
        a.erase(a.begin());
    }

    for (int i = 0; i < a.size(); i++)  //������ż˳��ѡ����(ģ�⸺��ѡ����������)
    {
        if (i % 2)
        {
            ans1 += a[i];
        }
        else
        {
            ans2 += a[i];
        }
    }

    cout << max(ans1, ans2) << endl;  
}
