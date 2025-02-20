//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include <climits>
//
//using namespace std;
//
//class Platform
//{
//public:
//	
//	long long left = 0;
//	long long right = 0;
//	long long length()const
//	{
//		return right - left;
//	}
//};
//
//class Space
//{
//public:
//	long long length;
//	long long begin;
//	long long end;
//};
//
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	vector<Platform> platform(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> platform[i].left >> platform[i].right;  //����ƽ̨����
//	}
//
//	vector<long long> ballPosition(M);
//	
//	for (int j = 0; j < M; j++)
//	{
//		cin >> ballPosition[j];  //����������
//	}
//	
//	//���������С�������򣬲�������֮��ļ��
//	vector<Space> space;  
//	sort(ballPosition.begin(), ballPosition.end()); //����ƽ̨�ϵ�����������������
//		
//	long long totalCost = 0;
//
//		
//	for (auto& plat : platform)  //����ÿ��ƽ̨
//	{
//		//����ƽ̨�ƶ�����Ե�Ĵ���
//		long long EdgeCost = min(abs(plat.right - ballPosition[0]), abs(plat.left - ballPosition[M - 1]));
//		
//		long long moveCost = LLONG_MAX;
//		bool haveValidSpace = false;
//
//		for (int i = 0; i < M - 1; i++)
//		{
//			long long spaceLength = ballPosition[i + 1] - ballPosition[i];
//			if(spaceLength >= plat.length())
//			{
//				haveValidSpace = true;
//				if (ballPosition[i+1] <= plat.left)//��Ч�����ȫ��ƽ̨���
//				{
//					moveCost = min(abs(plat.right - ballPosition[i + 1]), moveCost);
//				}
//				else if (ballPosition[i] >= plat.right)//��Ч�����ȫ��ƽ̨�Ҳ�
//				{
//					moveCost = min(abs(plat.left - ballPosition[i]), moveCost);
//					break;
//				}
//				else if (ballPosition[i] < plat.left && ballPosition[i+1]<plat.right)//��Ч���������ƽ̨���
//				{
//					moveCost = plat.right - ballPosition[i + 1];
//				}
//				else if (ballPosition[i] > plat.left && ballPosition[i + 1] > plat.right)//��Ч���������ƽ̨�Ҳ�
//				{
//					moveCost = ballPosition[i] - plat.left;
//				}
//				else  //��Ч���������ƽ̨
//				{
//					moveCost = 0;
//				}
//			}
//			
//		}
//
//		if (haveValidSpace) 
//		{
//			totalCost += min(moveCost, EdgeCost);
//		}
//		else 
//		{
//			totalCost += EdgeCost;
//		}
//	}
//		
//
//	cout << totalCost << endl;
//
//	return 0;
//}
//
