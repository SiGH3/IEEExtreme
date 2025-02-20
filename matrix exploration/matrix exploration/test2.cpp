#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���
struct node
{
    int x, y;
};

// ��������
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

int bfs(int n, int m, vector<node>& special, vector<vector<char>>& matrix)
{
    // ��ʼ��һ������Ԫ��Ϊ -1 �� n �� m �еľ���, �����洢 empty ��㵽 special ������С����
    vector<vector<int>> m_Dist(n, vector<int>(m, -1));

    // ����������
    queue<node> q;

    // ������ special ��� push ������
    for (auto& it : special)
    {
        q.push(it);
        m_Dist[it.x][it.y] = 0; // ���� special ���ľ���Ϊ 0
    }

    // ��ʼ BFS
    while (!q.empty())
    {
        node t = q.front();
        q.pop();

        // �����ĸ������ BFS ��չ
        for (int i = 0; i < 4; i++)
        {
            int xx = t.x + dx[i], yy = t.y + dy[i];
            // �жϱ߽磬�Ƿ��� empty ���
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && matrix[xx][yy] == '.')
            {
                // �����ǰ empty ���δ���ʹ���m_Dist[xx][yy] == -1�����ָ�С�ľ���
                if (m_Dist[xx][yy] == -1 || m_Dist[xx][yy] > m_Dist[t.x][t.y] + 1)
                {
                    m_Dist[xx][yy] = m_Dist[t.x][t.y] + 1;  // ����Ϊ��С����
                    q.push({ xx, yy });  // ������չ BFS
                }
            }
        }
    }

    // ���� total_Dist
    int total_Dist = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == '.' && m_Dist[i][j] != -1)
            {
                total_Dist += m_Dist[i][j];  // �ۼ����� empty ������С����
            }
        }
    }

    return total_Dist;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> matrix(N, vector<char>(M)); // �������
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    vector<node> special(K); // ��� special �ڵ�
    for (int i = 0; i < K; i++)
    {
        cin >> special[i].x >> special[i].y;
        special[i].x--;
        special[i].y--;
    }

    cout << bfs(N, M, special, matrix) << endl;

    return 0;
}
