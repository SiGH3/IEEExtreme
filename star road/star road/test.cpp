#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int max_count = 0;

int longestSub(const vector<int>& pathStars) 
{
	vector<int> lis;

	for (int star : pathStars) 
	{
		int left = 0, right = lis.size();

		while (left < right) 
		{
			int mid = left + (right - left) / 2;
			if (lis[mid] < star)
				left = mid + 1;
			else
				right = mid;
		}

		if (left < lis.size())
			lis[left] = star; // 替换已有元素
		else
			lis.push_back(star); // 添加新元素
	}

	return lis.size();
	/*if (pathStars.empty())
	{
		return 0;
	}
	vector<int> lis;
	for (int star : pathStars)
	{
		auto it = lower_bound(lis.begin(), lis.end(), star);
		if (it == lis.end()) 
		{
			lis.push_back(star);
		}
		else 
		{
			*it = star;
		}
	}
	return lis.size();*/
}


void dfs(int n, int p, vector<int>& star, const vector<vector<int>>&adj, vector<int> &pathStar)
{
	pathStar.push_back(star[n]);
	max_count = max(max_count, longestSub(pathStar));
	//top_star = max(star[n], top_star);
	for (auto neighbor : adj[n])
	{
		if (neighbor != p)
		{
			dfs(neighbor, n, star, adj, pathStar);
		}
	}
	pathStar.pop_back();
}


int main()
{
	int N;
	cin >> N;
	vector<int> star(N);
	for (int i = 0; i < N; i++)
	{
		cin >> star[i];
	}

	int u, v;
	vector<vector<int>> adjacencyList(N);
	for (int j = 0; j < N-1 ; j++)
	{
		cin >> u >> v;
		u--;
		v--;
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}

	
	
	for (int i = 0; i < N; i++) 
	{
		vector<int> pathStar;
		dfs(i, -1, star, adjacencyList, pathStar);
	}
	cout << max_count << endl;
	
	return 0;
}