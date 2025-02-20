//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int find_color(int x, int y) {
//    // Determine the color of point (x, y) recursively.
//    while (x > 1) {
//        int size = 1;
//        while ((size * 2 + 1) <= x) {
//            size = size * 2 + 1;
//        }
//        int inverted_triangle_start = size + 1;
//        int inverted_triangle_end = 2 * size + 1;
//
//        if (x >= inverted_triangle_start && x <= inverted_triangle_end) {
//            // In the blue inverted triangle
//            if (y > x - size) {
//                return 0; // Blue point
//            }
//        }
//        x -= size;
//        if (x <= 0) break;
//    }
//    return 1; // Red point
//}
//
//int main() {
//    int Q;
//    cin >> Q;
//    vector<int> results;
//    results.reserve(Q);
//
//    for (int i = 0; i < Q; ++i) {
//        int x, y;
//        cin >> x >> y;
//        results.push_back(find_color(x, y));
//    }
//
//    for (int result : results) {
//        cout << result << "\n";
//    }
//
//    return 0;
//}
