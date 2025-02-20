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
//		cin >> platform[i].left >> platform[i].right;  //输入平台坐标
//	}
//
//	vector<long long> ballPosition(M);
//	
//	for (int j = 0; j < M; j++)
//	{
//		cin >> ballPosition[j];  //输入球坐标
//	}
//	
//	//将球按坐标从小到大排序，并计算球之间的间隔
//	vector<Space> space;  
//	sort(ballPosition.begin(), ballPosition.end()); //将在平台上的球按照坐标升序排列
//		
//	long long totalCost = 0;
//
//		
//	for (auto& plat : platform)  //遍历每个平台
//	{
//		//计算平台移动到边缘的代价
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
//				if (ballPosition[i+1] <= plat.left)//有效间隔完全在平台左侧
//				{
//					moveCost = min(abs(plat.right - ballPosition[i + 1]), moveCost);
//				}
//				else if (ballPosition[i] >= plat.right)//有效间隔完全在平台右侧
//				{
//					moveCost = min(abs(plat.left - ballPosition[i]), moveCost);
//					break;
//				}
//				else if (ballPosition[i] < plat.left && ballPosition[i+1]<plat.right)//有效间隔部分在平台左侧
//				{
//					moveCost = plat.right - ballPosition[i + 1];
//				}
//				else if (ballPosition[i] > plat.left && ballPosition[i + 1] > plat.right)//有效间隔部分在平台右侧
//				{
//					moveCost = ballPosition[i] - plat.left;
//				}
//				else  //有效间隔覆盖了平台
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
