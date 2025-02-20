#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swapMaximize(string& num, int k, string& maxNum)
{
    if (k == 0)
    {
        if (num > maxNum)
            maxNum = num;
        return;
    }

    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] > num[i])
            {
                swap(num[i], num[j]);
                swapMaximize(num, k - 1, maxNum);
                swap(num[i], num[j]);

                if (num > maxNum)
                    maxNum = num;
            }
        }
    }
}

int main()
{
    string N;
    int K;
    cin >> N >> K;

    string maxNumber = N;
    swapMaximize(N, K, maxNumber);

    cout << maxNumber << endl;

    return 0;
}
