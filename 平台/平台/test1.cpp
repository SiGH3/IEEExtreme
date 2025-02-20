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
//	for (auto& plat : platform)  //����ÿ��ƽ̨
//	{
//		//����ƽ̨�ƶ�����Ե�Ĵ���
//		long long minEdgeCost = min(abs(plat.right - ballPosition[0]), abs(plat.left - ballPosition[M - 1]));
//
//		for (auto& spa : space)//����ÿ�����
//		{
//			if (spa.length >= plat.length())//����Ч���
//			{
//				validSpaceCost.push_back(min(abs(plat.left - spa.begin), abs(plat.right - spa.end)));//��ƽ̨�ƶ�����Ч�������Ҫ�Ĵ���
//			}
//		}
//
//		if (!validSpaceCost.empty()) //������Ч���
//		{
//			//�����ƶ�����Ч�������С����
//			long long minSpaceCost = *min_element(validSpaceCost.begin(), validSpaceCost.end());
//			totalCost += min(minSpaceCost, minEdgeCost);
//		}
//
//		else  //��������Ч���
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
