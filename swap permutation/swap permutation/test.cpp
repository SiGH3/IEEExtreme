#include <iostream>
#include <vector>


using namespace std;

// ɾ��һ�������ԣ����Ƿ���ڴ�1��K��·��
bool test01(const vector <pair<int, int>>& swaps, int skip, int K)//���뽻���ԣ�Ҫɾ���Ľ����ԣ�λ��K
{
    //��ʼ��Ԫ��1��λ��Ϊ1
    int pos = 1;

    for (int i = 0; i < swaps.size(); i++)
    {
        if (i != skip)
        {
            //��¼�任�Ե�λ��
            int u = swaps[i].first;
            int v = swaps[i].second;

            //���Ԫ��1�ڱ任���е���һλ���ϣ���¼�任���λ��
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
    
    return pos == K; //������Ԫ��1�Ƿ���λ��K��

}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> swaps(M);
    for (int i = 0; i < M; ++i) {
        cin >> swaps[i].first >> swaps[i].second;
    }

    // �����Ƴ�ÿ������������Ƿ���·����1��K
    for (int i = 0; i < M; ++i)
    {
        // ��Ҫȷ��������һ�������ܹ���Ԫ��1����K
        if (test01(swaps, i, K)) 
        {
            cout << i + 1 << endl; // ������
            break; 
        }
    }

    return 0;
}
