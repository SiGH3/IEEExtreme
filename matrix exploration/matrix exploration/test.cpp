//#include <iostream>
//#include <queue>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
////���
//struct node
//{
//	int x, y;
//};
//
//
//
////��������
//vector<int> dx = { -1, 1, 0, 0 };
//vector<int> dy = { 0, 0, -1, 1 };
//
//int bfs(int n, int m,vector<node> &special,vector<vector<char>> &matrix)//������������Сn*m������ڵ㣬����
//{
//	//����������
//	queue<node> q;
//
//	//��ʼ��һ������Ԫ��Ϊ-1����x��y�еľ���,��������empty��㵽special���ľ���
//	vector<vector<int>> m_Dist(n, vector<int>(m, -1));
//
//	//������special���push�����У�
//	for (auto it = special.begin(); it != special.end(); ++it) //����special���
//	{
//		q.push(*it);
//		m_Dist[it->x][it->y] = 0; //����special���ľ���Ϊ0
//	}
//
//	while (!q.empty())
//	{
//		//����ͷ��Ϊ��ǰҪ�����Ŀ����
//		node t = q.front();
//
//		//����BFS
//		for (int i = 0; i <= 3; i++)
//		{
//			int xx = t.x + dx[i], yy = t.y + dy[i];
//			//�жϱ߽磬�Ƿ���empty��㣬�����Ƿ�Ϊ0
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
//	vector<vector<char>> matrix(N, vector<char>(M));  //�������
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	vector<node> special(K);    //���special�ڵ�
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