#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string S;
	getline(cin, S);

	int length = S.length();
	int N = 2 * length;
	if (N > 2 * length)
	{
		N = 2 * length;
	}

	int A = 1;
	int B = N;

	vector<int> left(N + 1, 0);
	vector<int> right(N + 1, 0);

	for (int i = 1; i < N; i++)
	{
		left[i] = i + 1;
		right[i] = 0;
	}
	left[N] = 0;
	right[N] = 0;

	cout << N << " " << A << " " << B << endl;
	for (int i = 1; i <= N; i++) {
		cout << left[i] << " " << right[i] << endl;
	}

	return 0;

}