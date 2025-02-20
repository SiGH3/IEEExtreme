#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



//动态规划计算子数组的最优代价
int optCost(vector<int>& subArr)
{
	int n = subArr.size();

	if (n == 1)
	{
		return subArr[0];
	}

	vector<int> sums;
	for (int i = 0; i < n / 2; ++i) 
	{
		sums.push_back(subArr[i] + subArr[n - 1 - i]);
	}
	if (n % 2 == 1) 
	{
		sums.push_back(subArr[n / 2]);
	}
	return *max_element(sums.begin(), sums.end());
	/*vector<int> dp(n);
	dp[0] = subArr[0];
	dp[1] = max(subArr[0], subArr[1]); 

	for (int i = 2; i < n; i++) 
	{
		
		dp[i] = min(dp[i], max(dp[i - 2], subArr[i - 1] + subArr[i]));

		
		dp[i] = min(dp[i], dp[i - 1]);
	}
	return dp[n - 1];*/
}

//void solve(int N,vector<int> &arr,int x,int &result)
//{
//	
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = i + 1; j <= N; j++) 
//		{
//			vector<int> subarray(arr.begin() + i, arr.begin() + j);
//			int min_cost = optCost(subarray);
//
//			if (min_cost <= x) 
//			{
//				// 计算子数组最右边和最左边元素之差
//				result += (subarray.back() - subarray.front());
//			}
//		}
//	}
//}

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<int> iniArr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> iniArr[i]; 
	}

	vector<int> result;
	for (int j = 0; j < Q; j++)
	{
		int x;
		int sum = 0;
		cin >> x;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = i; j < N; ++j) 
			{
				vector<int> subarray(iniArr.begin() + i, iniArr.begin() + j + 1);
				if (optCost(subarray) <= x)
				{
					sum += (iniArr[j] - iniArr[i]);
				}
			}
		}
		result.push_back(sum); 
	}

	for (const auto& res : result) 
	{
		cout << res << endl;
	}
		
	
	return 0;
}