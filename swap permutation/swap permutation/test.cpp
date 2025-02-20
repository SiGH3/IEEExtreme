#include <iostream>
#include <vector>


using namespace std;

// 删除一个交换对，看是否存在从1到K的路径
bool test01(const vector <pair<int, int>>& swaps, int skip, int K)//传入交换对，要删除的交换对，位置K
{
    //初始化元素1的位置为1
    int pos = 1;

    for (int i = 0; i < swaps.size(); i++)
    {
        if (i != skip)
        {
            //记录变换对的位置
            int u = swaps[i].first;
            int v = swaps[i].second;

            //如果元素1在变换对中的任一位置上，记录变换后的位置
            if (pos == u)
            {
                pos = v;
            }
            else if (pos == v)
            {
                pos = u;
            }
        }
    }
    
    return pos == K; //检查最后元素1是否在位置K上

}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> swaps(M);
    for (int i = 0; i < M; ++i) {
        cin >> swaps[i].first >> swaps[i].second;
    }

    // 尝试移除每个交换并检查是否还有路径从1到K
    for (int i = 0; i < M; ++i)
    {
        // 需要确保至少有一个交换能够让元素1到达K
        if (test01(swaps, i, K)) 
        {
            cout << i + 1 << endl; // 输出结果
            break; 
        }
    }

    return 0;
}
