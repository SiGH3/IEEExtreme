//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//// 计算子数组的最优成本
//int calculateOptimalCost(const vector<int>& subarray) {
//    int n = subarray.size();
//    if (n == 1) return subarray[0];
//
//    vector<int> sums;
//    for (int i = 0; i < n / 2; ++i) {
//        sums.push_back(subarray[i] + subarray[n - 1 - i]);
//    }
//    if (n % 2 == 1) {
//        sums.push_back(subarray[n / 2]);
//    }
//    return *max_element(sums.begin(), sums.end());
//}
//
//int main() {
//    int N, Q;
//    cin >> N >> Q;
//    vector<int> A(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> A[i];
//    }
//
//    while (Q--) {
//        int x;
//        cin >> x;
//        long long result = 0;
//
//        for (int i = 0; i < N; ++i) {
//            for (int j = i; j < N; ++j) {
//                vector<int> subarray(A.begin() + i, A.begin() + j + 1);
//                if (calculateOptimalCost(subarray) <= x) {
//                    result += (A[j] - A[i]);
//                }
//            }
//        }
//        cout << result << endl;
//    }
//
//    return 0;
//}
