//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <stack>
//
//using namespace std;
//
//int N;
//vector<int> star;
//vector<vector<int>> adjacencyList;
//vector<int> dp;
//vector<int> compressed_star;
//vector<int> tree;
//vector<int> idx_stack;
//vector<int> val_stack;
//int max_count = 0;
//
//// Compress the star ratings to range 1..N
//void compress_star_ratings() {
//    vector<int> temp = star;
//    sort(temp.begin(), temp.end());
//    temp.erase(unique(temp.begin(), temp.end()), temp.end());
//    compressed_star.resize(N);
//    for (int i = 0; i < N; ++i) {
//        compressed_star[i] = lower_bound(temp.begin(), temp.end(), star[i]) - temp.begin() + 1;
//    }
//}
//
//// Segment tree query
//int query(int node, int l, int r, int ql, int qr) {
//    if (qr < l || r < ql) return 0;
//    if (ql <= l && r <= qr) return tree[node];
//    int mid = (l + r) / 2;
//    return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
//}
//
//// Segment tree update with undo capability
//void update(int node, int l, int r, int pos, int val) {
//    if (l == r) {
//        idx_stack.push_back(node);
//        val_stack.push_back(tree[node]);
//        tree[node] = max(tree[node], val);
//    }
//    else {
//        int mid = (l + r) / 2;
//        if (pos <= mid) {
//            update(2 * node, l, mid, pos, val);
//        }
//        else {
//            update(2 * node + 1, mid + 1, r, pos, val);
//        }
//        idx_stack.push_back(node);
//        val_stack.push_back(tree[node]);
//        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
//    }
//}
//
//
//void dfs(int u, int parent) {
//    int max_dp = query(1, 1, N, 1, compressed_star[u] - 1);
//    dp[u] = max_dp + 1;
//    max_count = max(max_count, dp[u]);
//    update(1, 1, N, compressed_star[u], dp[u]);
//    for (int v : adjacencyList[u]) {
//        if (v != parent) {
//            dfs(v, u);
//        }
//    }
//    while (!idx_stack.empty()) {
//        int idx = idx_stack.back();
//        int val = val_stack.back();
//        idx_stack.pop_back();
//        val_stack.pop_back();
//        tree[idx] = val;
//    }
//}
//
//int main() {
//    cin >> N;
//    star.resize(N);
//    dp.resize(N);
//    adjacencyList.resize(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> star[i];
//    }
//    int u, v;
//    for (int j = 0; j < N - 1; ++j) {
//        cin >> u >> v;
//        u--; v--;
//        adjacencyList[u].push_back(v);
//        adjacencyList[v].push_back(u);
//    }
//
//    compress_star_ratings();
//    tree.resize(4 * N, 0);
//    dfs(0, -1);
//    cout << max_count << endl;
//    return 0;
//}
