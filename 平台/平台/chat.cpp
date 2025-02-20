#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <climits>

using namespace std;

class Platform
{
public:
    long long left = 0;
    long long right = 0;
    long long length() const
    {
        return right - left;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Platform> platforms(N);
    for (int i = 0; i < N; i++)
    {
        cin >> platforms[i].left >> platforms[i].right;  // ����ƽ̨����
    }

    set<long long> ballPositions;
    for (int j = 0; j < M; j++)
    {
        long long pos;
        cin >> pos;  // ����������
        ballPositions.insert(pos);
    }

    vector<long long> sortedBallPositions(ballPositions.begin(), ballPositions.end());

    long long totalCost = 0;

    for (auto& plat : platforms)
    {  // ����ÿ��ƽ̨
        long long minEdgeCost = min(abs(plat.right - *sortedBallPositions.begin()), abs(plat.left - *sortedBallPositions.rbegin()));
        long long minSpaceCost = LLONG_MAX;

        for (size_t i = 0; i < sortedBallPositions.size() - 1; i++)
        {
            long long spaceLength = sortedBallPositions[i + 1] - sortedBallPositions[i];   //��֮��ļ��
            if (spaceLength >= plat.length()) //����Ч���
            {
                long long costToLeft = abs(plat.left - sortedBallPositions[i]);
                long long costToRight = abs(plat.right - sortedBallPositions[i + 1]);
                minSpaceCost = min({ minSpaceCost, costToLeft, costToRight });
            }
        }

        totalCost += min(minEdgeCost, minSpaceCost);
    }

    cout << totalCost << endl;

    return 0;
}
