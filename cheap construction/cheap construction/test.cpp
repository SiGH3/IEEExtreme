//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void operation1(vector<int>& A, vector<int>& P, int l, int c, int r, int t)
//{
//	if (t == 0)
//	{
//		for (int i = l; i <= r; i++)
//		{
//			A[i] += c;
//		}
//	}
//	else if (t == 1)
//	{
//		for (int i = l; i <= r; i++)
//		{
//			A[P[i]] += c;
//		}
//	}
//}
//
//int operation2(vector<int>& A, vector<int>& P, int l, int r, int t)
//{
//	int sum = 0;
//	if (t == 2)
//	{
//		for (int i = l; i <= r; i++)
//		{
//			sum += A[i];
//		}
//	}
//	else if (t == 3)
//	{
//		for (int i = l; i <= r; i++)
//		{
//			sum += A[P[i]];
//		}
//	}
//
//	return sum;
//}
//
//
//int main()
//{
//	int N, Q;
//
//
//	cin >> N >> Q;
//	vector<int> P(N+1);
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> P[i];
//		//P[i]--;
//	}
//
//	vector<int> A(N+1, 0);
//
//	vector<int> putout;
//	for (int j = 0; j < Q; j++)
//	{
//		int l, r, c, T;
//		cin >> T;
//		if (T == 0 || T == 1)
//		{
//			cin >> l >> r >> c;
//			/*l--;
//			r--;*/
//			operation1(A, P, l, c, r, T);
//		}
//		else if (T == 2 || T == 3)
//		{
//			cin >> l >> r;
//			/*l--;
//			r--;*/
//			putout.push_back(operation2(A, P, l, r, T));
//		}
//	}
//
//	for (auto val : putout)
//	{
//		cout << val << endl;
//	}
//
//	return 0;
//}