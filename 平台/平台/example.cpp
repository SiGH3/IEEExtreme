//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<assert.h>
//
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//const int MAX_N = 100000;
//const int MAX_M = 100000;
//const int MAX_COORD = 100000000;
//
//struct Platform {
//    int x1, x2;
//    int length;
//    int min_cost;
//
//    Platform() {}
//
//    Platform(int x1, int x2) {
//        this->x1 = x1;
//        this->x2 = x2;
//        length = x2 - x1;
//        min_cost = INF;
//    }
//
//    void mirror() {
//        int aux = x1;
//        x1 = -x2;
//        x2 = -aux;
//    }
//
//    bool operator<(const Platform& other) const {
//        return x2 < other.x2;
//    }
//
//    void update_cost(int new_cost) {
//        min_cost = min(min_cost, new_cost);
//    }
//};
//
//struct Gap {
//    int length;
//    int right_end;
//
//    Gap(int length, int right_end) {
//        this->length = length;
//        this->right_end = right_end;
//    }
//};
//
//int n, m;
//Platform platforms[MAX_N];
//int balls[MAX_M];
//
//void read() {
//    cin >> n >> m;
//    assert(1 <= n && n <= MAX_N);
//    assert(1 <= m && m <= MAX_M);
//    for (int i = 0; i < n; ++i) {
//        int x1, x2;
//        cin >> x1 >> x2;
//        assert(-MAX_COORD <= x1 && x1 < x2 && x2 <= MAX_COORD);
//        platforms[i] = Platform(x1, x2);
//    }
//    for (int i = 0; i < m; ++i) {
//        cin >> balls[i];
//        assert(-MAX_COORD <= balls[i] && balls[i] <= MAX_COORD);
//    }
//}
//
//void mirror() {
//    for (int i = 0; i < n; ++i)
//        platforms[i].mirror();
//    for (int i = 0; i < m; ++i)
//        balls[i] = -balls[i];
//}
//
//void solve() {
//    sort(platforms, platforms + n);
//    sort(balls, balls + m);
//
//    vector<Gap> gapStack;
//    gapStack.push_back(Gap(INF, balls[0]));
//
//    int p = 1;
//    for (int i = 0; i < n; ++i) {
//        while (p < m && balls[p] <= platforms[i].x2) {
//            int current_length = balls[p] - balls[p - 1];
//            while (gapStack.back().length <= current_length)
//                gapStack.pop_back();
//            gapStack.push_back(Gap(current_length, balls[p]));
//            ++p;
//        }
//
//        if (platforms[i].x2 <= balls[0] || platforms[i].x1 >= balls[m - 1]) {
//            platforms[i].update_cost(0);
//            continue;
//        }
//
//        if (p < m && platforms[i].x1 >= balls[p - 1] && platforms[i].x2 <= balls[p]) {
//            platforms[i].update_cost(0);
//            continue;
//        }
//
//        int left = 0, right = ((int)gapStack.size()) - 1, mid;
//        while (left != right) {
//            mid = (left + right + 1) / 2;
//            if (gapStack[mid].length >= platforms[i].length) {
//                left = mid;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//        platforms[i].update_cost(platforms[i].x2 - gapStack[left].right_end);
//    }
//}
//
//void write() {
//    long long sol = 0;
//    for (int i = 0; i < n; ++i)
//        sol += platforms[i].min_cost;
//    cout << sol << "\n";
//}
//
//int main() {
//    read();
//    solve();
//    mirror();
//    solve();
//    write();
//}