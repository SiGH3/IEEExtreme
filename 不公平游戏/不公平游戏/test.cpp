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
        if (b > 0)  //先把所有正数加起来
        {
            ans1 += b, ans2 += b;
        }
        else a.push_back(b);   //负数存入a中
    }

    sort(a.begin(), a.end(), greater<int>());  //将负数降序排列（从最小到最大，即从最“少负”的到最“多负”的）。

    if (a.size() == n)   //如果全是负数，按从最少负到最多负顺序加起来
    {
        ans1 += a[0];
        ans2 += a[0];
        a.erase(a.begin());
    }

    for (int i = 0; i < a.size(); i++)  //按照奇偶顺序选择负数(模拟负数选择的两种情况)
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
