#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int aux, n, k; cin >> aux >> n >> k;
    vector<pair<int, int> > swaps(n + 2);
    vector<int> begin_position(n + 2, 0), end_position(n + 2, 0);
    for (int i = 1; i <= n; i += 1) {
        int x, y; cin >> x >> y;
        swaps[i] = { x, y };
    }

    begin_position[0] = 1;
    end_position[n + 1] = k;
    for (int i = 1; i <= n; i += 1) {
        int position = begin_position[i - 1];
        if (swaps[i].first == position or swaps[i].second == position) {
            begin_position[i] = swaps[i].first + swaps[i].second - position;
        }
        else {
            begin_position[i] = position;
        }
    }

    for (int i = n; i; i -= 1) {
        int position = end_position[i + 1];
        if (swaps[i].first == position or swaps[i].second == position) {
            end_position[i] = swaps[i].first + swaps[i].second - position;
        }
        else {
            end_position[i] = position;
        }
    }

    for (int i = 1; i <= n; i += 1) {
        if (begin_position[i - 1] == end_position[i + 1]) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
