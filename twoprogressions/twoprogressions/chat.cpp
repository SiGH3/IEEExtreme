//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <algorithm>
//
//using namespace std;
//
//bool is_Progression(const vector<int>& v) {
//    if (v.size() < 2) return false;
//    int r = v[1] - v[0];
//    for (int i = 1; i < v.size(); i++) {
//        if (v[i] - v[i - 1] != r) return false;
//    }
//    return true;
//}
//
//tuple<int, int, int> find_best_progression(const vector<int>& p1, const vector<int>& p2) {
//    if (!is_Progression(p1) || !is_Progression(p2)) return { -1, -1, -1 };
//
//    int first = p1[0];
//    int ratio = p1[1] - p1[0];
//    int length = p1.size();
//
//    return { first, ratio, length };
//}
//
//vector<int> solve(const vector<int>& v) {
//    vector<int> best_result = { -1 }; // 默认无解
//
//    // 遍历所有可能的组合
//    for (int i = 0; i < v.size(); i++) {
//        for (int j = i + 1; j < v.size(); j++) {
//            vector<int> p1 = { v[i], v[j] };
//            vector<int> p2;
//            int d1 = v[j] - v[i];
//
//            // 填充 p1 和 p2
//            for (int k = 0; k < v.size(); k++) {
//                if (k != i && k != j) {
//                    if (p1.size() > 1 && v[k] - p1.back() == d1) {
//                        p1.push_back(v[k]);
//                    }
//                    else {
//                        p2.push_back(v[k]);
//                    }
//                }
//            }
//
//            // 获取当前组合的最佳结果
//            auto result = find_best_progression(p1, p2);
//            if (get<0>(result) != -1) {
//                // 比较当前结果与最佳结果
//                if (best_result[0] == -1 ||
//                    (get<0>(result) < best_result[0]) ||
//                    (get<0>(result) == best_result[0] && get<1>(result) < best_result[1]) ||
//                    (get<0>(result) == best_result[0] && get<1>(result) == best_result[1] && get<2>(result) < best_result[2])) {
//                    best_result = { get<0>(result), get<1>(result), get<2>(result) };
//                }
//            }
//        }
//    }
//
//    return best_result;
//}
//
//void putout(const vector<vector<int>>& p) {
//    for (const auto& result : p) {
//        if (result[0] == -1) {
//            cout << -1 << endl;
//        }
//        else {
//            for (const auto val : result) {
//                cout << val << " ";
//            }
//            cout << endl;
//        }
//    }
//}
//
//int main() {
//    int T, N;
//    cin >> T;
//    vector<vector<int>> result;
//
//    while (T--) {
//        cin >> N;
//        vector<int> iniProgression(N);  // 初始数列
//        for (int i = 0; i < N; i++) {
//            cin >> iniProgression[i];
//        }
//        result.push_back(solve(iniProgression));
//    }
//    putout(result);
//
//    return 0;
//}
