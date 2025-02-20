#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//É¨ÃèÏß
class Edge
{
public:
	int x, y1, y2, lr;
};

bool compareEdge(const Edge& a, const Edge& b)  //ÅÅÐò±ê×¼£ººá×ø±ê
{
	return a.x < b.x;
}

int main()
{
	long long N, K, L;
	cin >> N >> K >> L;

	long long area = 0;

	//long long sideLength = 2 * L;
	//if (sideLength <= K)
	//{
	//	area = N * sideLength * sideLength;
	//}

	//else 
	//{
		Edge edge;

		vector<Edge> e;
		for (int i = 0; i < N; i++)
		{
			int x1 = i * K - L;
			int x2 = i * K + L;
			int y1 = i * K - L;
			int y2 = i * K + L;
			e.push_back({ x1,y1,y2,1 });  //×ó
			e.push_back({ x2,y1,y2,-1 });  //ÓÒ
		}
		sort(e.begin(), e.end(), compareEdge);

		int old_x = e[0].x;
		set<pair<int, int>> yHeight;

		for (auto& curEdge : e)
		{
			while (old_x < curEdge.x)
			{

				long long height = 0;
				int old_y = -1e9;
				

				for (auto& yH : yHeight)
				{
					int start = max(old_y, yH.first);
					if (yH.second > start)
					{
						height += yH.second - start;
					}
					old_y = max(old_y, yH.second);
				}

				area += height;
				old_x++;
			}

			if (curEdge.lr == 1)
			{
				yHeight.emplace(curEdge.y1, curEdge.y2);
			}
			else
			{
				yHeight.erase(yHeight.find(make_pair(curEdge.y1, curEdge.y2)));
			}

		}
	//}
	
	cout << area;

	return 0;

}