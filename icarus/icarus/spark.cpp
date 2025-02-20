//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include <string>
//
//using namespace std;
//
//struct Node {
//    int left = 0;
//    int right = 0;
//};
//
//int main() {
//    string S;
//    cin >> S;
//
//    if (S.empty()) {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    int N = 2; // Start from 2 because nodes are 1-indexed, and we already have nodes 1 and 2
//    int A = 2;
//    int B = 1;
//
//    vector<Node> nodes(2 * S.size() + 3); // Allocate maximum possible nodes
//    vector<int> parent(2 * S.size() + 3, 0); // Parent pointers
//    map<pair<int, int>, int> visited; // Map to keep track of visited states (node, position in S)
//
//    int nodeIndex = 2; // Next available node index
//    parent[A] = 0; // Node A has no parent
//    int currentNode = A;
//    queue<pair<int, int>> q; // Queue for BFS: (current node, position in S)
//    q.push({ currentNode, 0 });
//    visited[{currentNode, 0}] = 1;
//
//    while (!q.empty()) {
//        auto [currNode, pos] = q.front();
//        q.pop();
//        int nextPos = (pos + 1) % S.size();
//        char move = S[pos];
//
//        int nextNode = currNode;
//        if (move == 'L') {
//            if (nodes[currNode].left == 0) {
//                nodeIndex++;
//                nodes[currNode].left = nodeIndex;
//                parent[nodeIndex] = currNode;
//            }
//            nextNode = nodes[currNode].left;
//        }
//        else if (move == 'R') {
//            if (nodes[currNode].right == 0) {
//                nodeIndex++;
//                nodes[currNode].right = nodeIndex;
//                parent[nodeIndex] = currNode;
//            }
//            nextNode = nodes[currNode].right;
//        }
//        else if (move == 'U') {
//            if (parent[currNode] != 0 && parent[currNode] != B) {
//                nextNode = parent[currNode];
//            }
//            else {
//                // Skip 'U' if parent doesn't exist or parent is B
//                nextNode = currNode;
//                nextPos = (nextPos + S.size() - 1) % S.size(); // Adjust nextPos since we skipped
//                continue;
//            }
//        }
//        // Check if this state has been visited
//        if (visited.find({ nextNode, nextPos }) == visited.end()) {
//            visited[{nextNode, nextPos}] = 1;
//            q.push({ nextNode, nextPos });
//        }
//    }
//
//    if (nodeIndex > 2 * S.size()) {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    // Output
//    cout << nodeIndex << " " << A << " " << B << endl;
//    for (int i = 1; i <= nodeIndex; ++i) {
//        cout << nodes[i].left << " " << nodes[i].right << endl;
//    }
//
//    return 0;
//}
