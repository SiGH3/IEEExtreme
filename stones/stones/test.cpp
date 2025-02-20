//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//int largestRec(vector<int>& h)
//{
//    stack<int> s;
//    int max_area = 0;
//    h.push_back(0);
//
//    for (int i = 0; i < h.size(); i++)
//    {
//        while (!s.empty() && h[s.top()] > h[i])
//        {
//            int height = h[s.top()];
//            s.pop();
//            int w = i;
//            if (!s.empty()) 
//            {
//                w -= s.top() + 1;
//            }
//            max_area = max(max_area, height * w);
//        }
//        s.push(i);
//    }
//
//    return max_area;
//}
//
//
//int solve(int N, int X, vector<int>& h)
//{
//    vector<int> ini_h = h;
//    int ini_area = largestRec(ini_h);
//
//    int max_area = ini_area;
//
//    for (int i = 0; i < N; i++)
//    {
//        int ini_h = h[i];
//        if (ini_h < X)
//        {
//            h[i] = X;
//            max_area = max(max_area, largestRec(h));
//            h[i] = ini_h;
//        }
//    }
//
//    return max_area;
//}
//
//int main() 
//{
//
//    int N, X;
//    cin >> N >> X;
//
//    vector<int> heights(N);
//    for (int i = 0; i < N; i++) 
//    {
//        cin >> heights[i];
//    }
//
//    int result = solve(N, X, heights);
//    cout << result << endl;
//
//    return 0;
//}
