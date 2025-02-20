//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//struct Event {
//    int x, y1, y2, type; // type: 1 for left edge, -1 for right edge
//    Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
//};
//
//// �Զ����¼����򣺰�x��������
//bool compareEvents(const Event& a, const Event& b) {
//    return a.x < b.x;
//}
//
//int calculateArea(int N, int K, int L) {
//    vector<Event> events;
//
//    // ����ÿ�������ε����ұ߽��¼�
//    for (int i = 0; i < N; i++) {
//        int x1 = i * K - L;
//        int y1 = i * K - L;
//        int x2 = i * K + L;
//        int y2 = i * K + L;
//        events.emplace_back(x1, y1, y2, 1);  // ��߽�
//        events.emplace_back(x2, y1, y2, -1); // �ұ߽�
//    }
//
//    // ��x���������¼�
//    sort(events.begin(), events.end(), compareEvents);
//
//    // ɨ�����㷨�����
//    int total_area = 0;
//    int last_x = events[0].x;
//    multiset<pair<int, int>> y_segments;
//
//    for (const auto& event : events) {
//        int x = event.x;
//        int y1 = event.y1;
//        int y2 = event.y2;
//        int type = event.type;
//
//        // ���㵱ǰ x ��Χ�Ŀ��
//        int width = x - last_x;
//        if (width > 0 && !y_segments.empty()) {
//            // ���㵱ǰy��Χ�ĸ߶�
//            int height = 0;
//            int last_y = -1e9;
//
//            for (const auto& seg : y_segments) {
//                int start = max(last_y, seg.first);
//                if (seg.second > start) {
//                    height += seg.second - start;
//                }
//                last_y = max(last_y, seg.second);
//            }
//
//            // �ۼ����
//            total_area += width * height;
//        }
//
//        // ����ɨ����״̬
//        if (type == 1) {
//            y_segments.emplace(y1, y2);
//        }
//        else {
//            y_segments.erase(y_segments.find(make_pair(y1, y2)));
//        }
//
//        last_x = x;
//    }
//
//    return total_area;
//}
//
//int main() {
//    int N, K, L;
//    cin >> N >> K >> L;
//    cout << calculateArea(N, K, L) << endl;
//    return 0;
//}
