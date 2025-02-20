//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//// Memoization dictionary
//unordered_map<string, double> memo;
//
//double dp(int r1, int b1, int r2, int b2) {
//    if (r1 == 0 && b1 == 0) {
//        return 0.0;  // Alice loses if she has no stones left
//    }
//    if (r2 == 0 && b2 == 0) {
//        return 1.0;  // Alice wins if Bob has no stones left
//    }
//
//    string key = to_string(r1) + "," + to_string(b1) + "," + to_string(r2) + "," + to_string(b2);
//    if (memo.find(key) != memo.end()) {
//        return memo[key];
//    }
//
//    // Probability of Alice winning
//    double prob = 0.0;
//    int total_choices = 0;
//
//    // If Alice chooses red
//    if (r1 > 0) {
//        if (r2 > 0) {
//            prob += (r1 / static_cast<double>(r1 + b1)) * (r2 / static_cast<double>(r2 + b2)) * dp(r1 - 1, b1, r2 - 1, b2);
//        }
//        else {
//            prob += (r1 / static_cast<double>(r1 + b1)) * dp(r1 - 1, b1, r2, b2);
//        }
//        total_choices += r1;
//    }
//
//    // If Alice chooses blue
//    if (b1 > 0) {
//        if (b2 > 0) {
//            prob += (b1 / static_cast<double>(r1 + b1)) * (b2 / static_cast<double>(r2 + b2)) * dp(r1, b1 - 1, r2, b2 - 1);
//        }
//        else {
//            prob += (b1 / static_cast<double>(r1 + b1)) * dp(r1, b1 - 1, r2, b2);
//        }
//        total_choices += b1;
//    }
//
//    // Normalize the probability by the number of choices
//    double result = prob / total_choices;
//    memo[key] = result;
//    return result;
//}
//
//int main() {
//    int R1, B1, R2, B2;
//    cout << "请输入四个整数: ";
//    cin >> R1 >> B1 >> R2 >> B2;
//    cout << fixed << setprecision(6) << alice_wins(R1, B1, R2, B2) << endl;
//    return 0;
//}
