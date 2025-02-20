#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// 线段树节点
struct SegmentTreeNode {
    ll sum;
    ll lazy;
    SegmentTreeNode() : sum(0), lazy(0) {}
};

// 线段树类
class SegmentTree {
private:
    vector<SegmentTreeNode> tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // 初始数组元素为0，无需处理
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
    }

    void push_down(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            int mid = (start + end) / 2;
            // 将lazy值下传给子节点
            tree[2 * node].sum += (mid - start + 1) * tree[node].lazy;
            tree[2 * node + 1].sum += (end - mid) * tree[node].lazy;

            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;

            tree[node].lazy = 0;
        }
    }

    void update_range(int node, int start, int end, int l, int r, ll val) {
        if (r < start || end < l) {
            // 不相交
            return;
        }
        if (l <= start && end <= r) {
            // 完全包含
            tree[node].sum += (end - start + 1) * val;
            tree[node].lazy += val;
            return;
        }
        // 部分重叠
        push_down(node, start, end);
        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }

    ll query_range(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // 不相交
            return 0;
        }
        if (l <= start && end <= r) {
            // 完全包含
            return tree[node].sum;
        }
        // 部分重叠
        push_down(node, start, end);
        int mid = (start + end) / 2;
        ll p1 = query_range(2 * node, start, mid, l, r);
        ll p2 = query_range(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int l, int r, ll val) {
        update_range(1, 1, n, l, r, val);
    }

    ll query(int l, int r) {
        return query_range(1, 1, n, l, r);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N + 1);
    vector<int> invP(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        invP[P[i]] = i; // 构建逆置换
    }

    SegmentTree segTree_A(N);   // 用于处理类型 0 和 2 的操作
    SegmentTree segTree_P(N);   // 用于处理类型 1 和 3 的操作

    vector<ll> output; // 存储查询结果

    for (int j = 0; j < Q; j++) {
        int T;
        cin >> T;
        if (T == 0) {
            int l, r, c;
            cin >> l >> r >> c;
            segTree_A.update(l, r, c);
        }
        else if (T == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            segTree_P.update(l, r, c);
        }
        else if (T == 2) {
            int l, r;
            cin >> l >> r;
            ll res = segTree_A.query(l, r);
            output.push_back(res);
        }
        else if (T == 3) {
            int l, r;
            cin >> l >> r;
            ll res = segTree_P.query(l, r);
            output.push_back(res);
        }
    }

    for (auto val : output) {
        cout << val << endl;
    }

    return 0;
}
