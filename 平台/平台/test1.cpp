//#include<iostream>
//#include<vector>
//#include<algorithm>
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
//
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
//	for (int i = 0; i < M - 1; i++)
//	{
//		Space temp;
//		temp.begin = ballPosition[i];
//		temp.end = ballPosition[i + 1];
//		temp.length = temp.end - temp.begin;
//		space.push_back(temp);
//	}
//
//	long long totalCost = 0;
//
//
//	vector<long long> validSpaceCost;
//	for (auto& plat : platform)  //遍历每个平台
//	{
//		//计算平台移动到边缘的代价
//		long long minEdgeCost = min(abs(plat.right - ballPosition[0]), abs(plat.left - ballPosition[M - 1]));
//
//		for (auto& spa : space)//遍历每个间隔
//		{
//			if (spa.length >= plat.length())//找有效间隔
//			{
//				validSpaceCost.push_back(min(abs(plat.left - spa.begin), abs(plat.right - spa.end)));//将平台移动到有效间隔所需要的代价
//			}
//		}
//
//		if (!validSpaceCost.empty()) //存在有效间隔
//		{
//			//计算移动到有效间隔的最小代价
//			long long minSpaceCost = *min_element(validSpaceCost.begin(), validSpaceCost.end());
//			totalCost += min(minSpaceCost, minEdgeCost);
//		}
//
//		else  //不存在有效间隔
//		{
//			totalCost += minEdgeCost;
//		}
//
//		validSpaceCost.clear();
//	}
//
//	cout << totalCost << endl;
//
//	return 0;
//}
//
