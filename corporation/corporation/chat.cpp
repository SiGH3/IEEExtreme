//#include <iostream>
//#include <vector>
//#include <numeric> 
//#include <algorithm> 
//
//using namespace std;
//
//void Event(vector<long long>& last_salary, vector<long long>& cur_salary, vector<int>& happiness, int t, int l, int r, long long c)
//{
//    for (int j = l; j <= r; j++)
//    {
//        if (t == 0)
//        {
//            cur_salary[j] = c;
//        }
//        else if (t == 1)
//        {
//            cur_salary[j] += c;
//        }
//        if (cur_salary[j] > last_salary[j])
//        {
//            happiness[j]++;
//        }
//        else if (cur_salary[j] < last_salary[j])
//        {
//            happiness[j]--;
//        }
//        last_salary[j] = cur_salary[j];
//    }
//}
//
//long long gcd(long long a, long long b)
//{
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//void Query(const vector<long long>& cur_salary, const vector<int>& happiness, int t, int l, int r, vector<pair<long long, long long>>& result)
//{
//    long long A = 0;
//    int B = r - l + 1;
//    if (t == 2)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            A += cur_salary[j];
//        }
//    }
//    else if (t == 3)
//    {
//        for (int j = l; j <= r; j++)
//        {
//            A += happiness[j];
//        }
//    }
//    long long divisor = gcd(abs(A), B);
//    A /= divisor;
//    B /= divisor;
//    result.emplace_back(A, B);
//}
//
//int main()
//{
//    int N, Q;
//    cin >> N >> Q;
//    vector<long long> last_salary(N), cur_salary(N);
//    vector<int> happiness(N, 0);
//    vector<pair<long long, long long>> result;
//    for (int i = 0; i < N; i++)
//    {
//        cin >> last_salary[i];
//        cur_salary[i] = last_salary[i];
//    }
//    int t, l, r;
//    long long c;
//    while (Q--)
//    {
//        cin >> t;
//        if (t == 0 || t == 1)
//        {
//            cin >> l >> r >> c;
//            l--; r--;
//            Event(last_salary, cur_salary, happiness, t, l, r, c);
//        }
//        else if (t == 2 || t == 3)
//        {
//            cin >> l >> r;
//            l--; r--;
//            Query(cur_salary, happiness, t, l, r, result);
//        }
//    }
//    for (const auto& res : result)
//    {
//        long long numerator = res.first;
//        long long denominator = res.second;
//        if (denominator == 1)
//        {
//            cout << numerator << '\n';
//        }
//        else
//        {
//            cout << numerator << '/' << denominator << '\n';
//        }
//    }
//    return 0;
//}
