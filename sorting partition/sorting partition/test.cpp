//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//
//using namespace std;
//
//int m_Partion(vector<int> &v)
//{
//	stack<int> s;
//	int m_Partition=0;
//
//	
//	for (auto &it :v)
//	{
//		if (s.empty())
//		{
//			m_Partition++;
//			s.push(it);
//		}
//		else if(!s.empty() && it>=s.top())
//		{
//			s.pop();
//			s.push(it);
//			m_Partition++;
//		}
//		
//	}
//
//	return m_Partition;
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> v[i];
//	}
//
//	cout << m_Partion(v) << endl;
//
//	return 0;
//}