#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool is_Progression(vector<int>& v)
{
	if (v.size() < 2)
	{
		return false;
	}
	int r = v[1]-v[0];
	if (r == 0)
	{
		return false;
	}
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i + 1] - v[i] != r)
		{
			return false;
		}
	}
	return true;
}




void solve(vector<int> &v)
{
	vector<int> p1, p2;
	int f = v[0];
	int r = 0;
	int l = 0;
	vector<vector<int>> result;

	int r1 = v[1] - v[0];
	int r2 = v[2] - v[1];
	int r3 = v[2] - v[0];

	//abc|ab,c|ac,b|a,bc
	// 
	//#1 abc
	if (r2 == r1)
	{
		p1.push_back(v[0]);
		p1.push_back(v[1]);
		p1.push_back(v[2]);
		for (int i = 3; i < v.size()-1; i++)
		{
			int j = 2;			
			if (v[i] - v[j] == r1)
			{
			    p1.push_back(v[i]);  //如果找到在p1中的数，移动指针j到i的位置，继续寻找
				j = i;
			}
			else
			{
			    p2.push_back(v[i]); //如果没有找到在p1中的数，指针j不动，只移动指针i，继续寻找
			}
		}
		if (p2.empty())
		{
			f = p1[0];
			r = r1;
			l = 2;
			result.push_back(vector<int>({ f,r,l }));
			
		}
		else if (is_Progression(p1) && is_Progression(p2))
		{
			f = p1[0];
			r = r1;
			l = p1.size();
			result.push_back(vector<int>({ f,r,l }));
		}
		else  //ab,c||ac,b||a,bc
		{
			int j = 1;
			for (int i = 3; i < v.size(); i++)
			{
				//#2 ab,c
				if (v[i] - v[j] == r1)
				{
					p1.push_back(v[0]);
					p1.push_back(v[1]);
					p1.push_back(v[i]);

					p2.push_back(v[2]);
					j = i;
				}
				else
				{
					p2.push_back(v[i]);
				}
			}
			if (is_Progression(p1) && is_Progression(p2))
			{
				f = p1[0];
				r = r1;
				l = p1.size();
				result.push_back(vector<int>({ f,r,l }));
			}
			else //ac,b||a,bc
			{
				int j = 2;
				for (int i = 3; i < v.size(); i++)
				{
					//#3 ac,b
					if (v[i] - v[j] == r3)
					{
						p1.push_back(v[0]);
						p1.push_back(v[2]);
						p1.push_back(v[i]);

						p2.push_back(v[1]);
						j = i;
					}
					else
					{
						p2.push_back(v[i]);
					}
				}
				if (is_Progression(p1) && is_Progression(p2))
				{
					f = p1[0];
					r = r3;
					l = p1.size();
					result.push_back(vector<int>({ f,r,l }));
				}
				else //a,bc
				{
					int j = 2;
					for (int i = 3; i < v.size(); i++)
					{
						//#4 a,bc
						if (v[i] - v[j] == r2)
						{
							p1.push_back(v[1]);
							p1.push_back(v[2]);
							p1.push_back(v[i]);

							p2.push_back(v[0]);
							j = i;
						}
						else
						{
							p2.push_back(v[i]);
						}
					}
					if (is_Progression(p1) && is_Progression(p2))
					{
						f = p1[1];
						r = r2;
						l = p1.size();
						result.push_back(vector<int>({ f,r,l }));
					}
					else  //不能找到两个等差数列
					{
						result.push_back(vector<int>({-1}));
					}
					
				}
			}
		}

	}
	for (const auto Val : result)
	{
		for (auto val : Val)
		{
			cout << val << " ";
		}
		cout << '\n';
	}
	

}





int main()
{
	int T, N;
	cin >> T;
	vector<vector<int>> result;

	while (T--)
	{
		cin >> N;
		vector<int> iniProgression(N);  //初始数列
		for (int i = 0; i < N; i++)
		{
			cin >> iniProgression[i];
		}
		solve(iniProgression);
		
	}
	

	return 0;
}