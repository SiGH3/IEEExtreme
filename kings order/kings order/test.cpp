#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

// Function to find project order
string find_project_order(int N, int M, vector<int>& group_ids, vector<pair<int, int> >& dependencies) {
    // Initialize adjacency list and in-degree counts
    vector<vector<int> > adj_list(N);
    vector<int> in_degree(N, 0);

    // Build the graph
    for (int i = 0; i < dependencies.size(); ++i) {
        int A = dependencies[i].first - 1;  // Convert to 0-based index
        int B = dependencies[i].second - 1; // Convert to 0-based index
        adj_list[A].push_back(B);
        in_degree[B]++;
    }

    // Priority queue to prioritize based on group ID, then project ID
    typedef pair<int, int> Project; // Use pair instead of tuple
    priority_queue<Project, vector<Project>, greater<Project> > min_heap;

    // Initialize the heap with projects that have no dependencies
    for (int i = 0; i < N; ++i) {
        if (in_degree[i] == 0) {
            min_heap.push(make_pair(group_ids[i], i));
        }
    }

    vector<int> result;
    int count = 0;

    // Kahn's algorithm with priority on group ID and project ID
    while (!min_heap.empty()) {
        int group_id = min_heap.top().first;
        int proj_id = min_heap.top().second;
        min_heap.pop();
        result.push_back(proj_id + 1);  // Convert back to 1-based index
        count++;

        // For each dependent project, reduce in-degree
        for (int j = 0; j < adj_list[proj_id].size(); ++j) {
            int neighbor = adj_list[proj_id][j];
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                min_heap.push(make_pair(group_ids[neighbor], neighbor));
            }
        }
    }

    // If count is less than N, we detected a cycle
    if (count < N) return "-1";

    // Build output string using stringstream
    ostringstream output;
    for (int i = 0; i < result.size(); ++i) {
        output << result[i];
        if (i != result.size() - 1) output << " ";
    }
    return output.str();
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> group_ids(N);
    for (int i = 0; i < N; ++i) {
        cin >> group_ids[i];
    }

    vector<pair<int, int> > dependencies(M);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        dependencies[i] = make_pair(A, B);
    }

    // Find and print the project order
    cout << find_project_order(N, M, group_ids, dependencies) << endl;

    return 0;
}
