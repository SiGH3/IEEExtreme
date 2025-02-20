//#include <iostream>
//#include <queue>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
////结点
//struct node
//{
//	int x, y;
//};
//
//
//
////搜索方向
//vector<int> dx = { -1, 1, 0, 0 };
//vector<int> dy = { 0, 0, -1, 1 };
//
//int bfs(int n, int m,vector<node> &special,vector<vector<char>> &matrix)//传入参数矩阵大小n*m，特殊节点，矩阵
//{
//	//创建结点队列
//	queue<node> q;
//
//	//初始化一个所有元素为-1，的x行y列的矩阵,用来储存empty结点到special结点的距离
//	vector<vector<int>> m_Dist(n, vector<int>(m, -1));
//
//	//将所有special结点push进队列，
//	for (auto it = special.begin(); it != special.end(); ++it) //遍历special结点
//	{
//		q.push(*it);
//		m_Dist[it->x][it->y] = 0; //设置special结点的距离为0
//	}
//
//	while (!q.empty())
//	{
//		//队列头部为当前要处理的目标结点
//		node t = q.front();
//
//		//进行BFS
//		for (int i = 0; i <= 3; i++)
//		{
//			int xx = t.x + dx[i], yy = t.y + dy[i];
//			//判断边界，是否是empty结点，距离是否为0
//			if (xx >= 0 && xx < n && yy >= 0 && yy < m && matrix[xx][yy] == '.' && m_Dist[xx][yy] == -1)
//			{
//				m_Dist[xx][yy] = m_Dist[t.x][t.y] + 1;
//				q.push({ xx,yy });
//			}
//		}
//	}
//	
//	int total_Dist = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			if (matrix[i][j] == '.') 
//			{
//				total_Dist += m_Dist[i][j];
//			}
//		}
//	}
//
//	return total_Dist;
//}
//
//
//
//int main()
//{
//	int N, M, K;
//	cin >> N >> M >> K;
//
//
//	vector<vector<char>> matrix(N, vector<char>(M));  //输入矩阵
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	vector<node> special(K);    //标记special节点
//	for (int i = 0; i < K; i++)
//	{
//		cin >> special[i].x >> special[i].y;
//		special[i].x--;
//		special[i].y--;
//	}
//
//	cout << bfs(N, M, special, matrix) << endl;
//
//	return 0;
//}