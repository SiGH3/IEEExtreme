#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i) 
        {
            cin >> A[i];
        }

        vector<vector<ll>> val(N, vector<ll>(2));
        for (int i = 0; i < N; ++i) 
        {
            val[i][0] = A[i];      
            val[i][1] = -A[i];     
        }

        vector<vector<ll>> dp(N, vector<ll>(2));
        dp[0][0] = val[0][0];
        dp[0][1] = val[0][1];

        ll cur_max = max(dp[0][0], dp[0][1]);

        for (int i = 1; i < N; ++i) 
        {
            if (i % 2 == 1) 
            {
                
                dp[i][0] = max(dp[i - 1][0] + val[i][0], val[i][0]);
                dp[i][1] = max(dp[i - 1][1] + val[i][1], val[i][1]);
            }
            else 
            {
                
                dp[i][0] = max({ dp[i - 1][0] + val[i][0], dp[i - 1][1] + val[i][0], val[i][0] });
                dp[i][1] = max({ dp[i - 1][0] + val[i][1], dp[i - 1][1] + val[i][1], val[i][1] });
            }
            cur_max = max({ cur_max, dp[i][0], dp[i][1] });
        }

        cout << cur_max << endl;
    }
    return 0;
}
