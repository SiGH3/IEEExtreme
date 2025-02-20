#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 结点
struct node
{
    int x, y;
};

// 搜索方向
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

int bfs(int n, int m, vector<node>& special, vector<vector<char>>& matrix)
{
    // 初始化一个所有元素为 -1 的 n 行 m 列的矩阵, 用来存储 empty 结点到 special 结点的最小距离
    vector<vector<int>> m_Dist(n, vector<int>(m, -1));

    // 创建结点队列
    queue<node> q;

    // 将所有 special 结点 push 进队列
    for (auto& it : special)
    {
        q.push(it);
        m_Dist[it.x][it.y] = 0; // 设置 special 结点的距离为 0
    }

    // 开始 BFS
    while (!q.empty())
    {
        node t = q.front();
        q.pop();

        // 进行四个方向的 BFS 扩展
        for (int i = 0; i < 4; i++)
        {
            int xx = t.x + dx[i], yy = t.y + dy[i];
            // 判断边界，是否是 empty 结点
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && matrix[xx][yy] == '.')
            {
                // 如果当前 empty 结点未访问过（m_Dist[xx][yy] == -1）或发现更小的距离
                if (m_Dist[xx][yy] == -1 || m_Dist[xx][yy] > m_Dist[t.x][t.y] + 1)
                {
                    m_Dist[xx][yy] = m_Dist[t.x][t.y] + 1;  // 更新为最小距离
                    q.push({ xx, yy });  // 继续扩展 BFS
                }
            }
        }
    }

    // 计算 total_Dist
    int total_Dist = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == '.' && m_Dist[i][j] != -1)
            {
                total_Dist += m_Dist[i][j];  // 累加所有 empty 结点的最小距离
            }
        }
    }

    return total_Dist;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> matrix(N, vector<char>(M)); // 输入矩阵
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    vector<node> special(K); // 标记 special 节点
    for (int i = 0; i < K; i++)
    {
        cin >> special[i].x >> special[i].y;
        special[i].x--;
        special[i].y--;
    }

    cout << bfs(N, M, special, matrix) << endl;

    return 0;
}
