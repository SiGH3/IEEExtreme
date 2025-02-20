//#include <iostream>
//#include<vector>
//
//using namespace std;
//
//void Event(vector<int>& last_salary, vector<int> &cur_salary, int t,int l,int r,int c)
//{
//    if (t == 0)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            last_salary[j] = cur_salary[j];
//            cur_salary[j] = c;
//        }
//    }
//    else if (t == 1)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            last_salary[j] = cur_salary[j];
//            cur_salary[j] += c;
//        }
//    }
//}
//
//bool isIncrease(int last_salary, int cur_salary)
//{
//    
//        if (cur_salary > last_salary)
//        {
//            return true;
//        }
//        else if (cur_salary < last_salary)
//        {
//            return false;
//        }
//    
//}
//
//void Query(vector<int>& last_salary, vector<int>& cur_salary, vector<int> &happiness, int t, int l, int r)
//{
//    int A=0;
//    int B = r - l + 1;
//    if (t == 2)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            A += cur_salary[j];
//        }
//        if (A % B != 0)
//        {
//            cout << A << '/' << B;
//        }
//        else
//        {
//            cout << A / B;
//        }
//    }
//    else if (t == 3)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            if (isIncrease(last_salary[j], cur_salary[j]))
//            {
//                happiness[j]++;
//            }
//            else if (!isIncrease(last_salary[j], cur_salary[j]))
//            {
//                happiness[j]--;
//            }
//            A += happiness[j];
//
//        }
//        if (A % B != 0)
//        {
//            cout << A << '/' << B;
//        }
//        else
//        {
//            cout << A / B;
//        }
//
//    }
//}
//
//
//
//
//
//int main()
//{
//    int N, Q;
//    cin >> N >> Q;
//    vector<int> last_salary(N);
//    for (int i = 0; i < N; i++)
//    {
//        cin >> last_salary[i];
//    }
//    vector<int> cur_salary=last_salary;
//
//    int t, l, r, c;
//    vector<int> happiness(N,0);
//    while (Q--)
//    {
//        cin >> t;
//        if (t == 0 || t == 1)
//        {
//            cin >> l >> r >> c;
//            l--;
//            r--;
//            Event(last_salary,cur_salary,t,l,r,c);
//        }
//        else if (t == 2 || t == 3)
//        {
//            cin >> l >> r;
//            l--;
//            r--;
//            Query(last_salary, cur_salary, happiness, t, l, r);
//        }
//
//    }
//
//   
//    return 0;
//}