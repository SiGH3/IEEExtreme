//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int colored_marbles(vector<int>& L,int n)
//{
//    int totalSum = 0;
//    int jia = 0;
//    int kong = 0;
//    int bu = 0;
//    int j = 0;
//    sort(L.begin(),L.end(),greater<int>());
//    while (j < n) 
//    {
//        int currentnum = L[j];
//        int count = 1;
//        j++;
//        while (j < n  && currentnum == L[j])
//        {
//            count++;
//            j++;
//        }
//        if(j < n )
//        {
//            totalSum += currentnum * (((count - 2) / currentnum) + 1);
//            if (jia==0 && count % currentnum == 1)
//            {
//                jia = 1;
//            }
//            else 
//            {
//                totalSum += currentnum;
//                kong = 1;
//            }
//            if (count % currentnum > 1) {
//                kong = 1;
//            }
//            if (jia == 1 && kong == 1) {
//                bu = 1;
//            }
//        }
//    }
//    if (jia == 0 && kong == 0) {
//            totalSum ++;  
//    }
//    else if (jia == 0 && kong == 1) {
//
//    }
//    else if (jia == 1 && kong == 0) {
//        totalSum++;
//    }
//    else if (jia == 1 && kong == 1 && bu==0) {
//
//    }
//
//
//
//
//    return totalSum;
//}
//
//int main() 
//{
//    int T;
//    cin >> T;
//    for (; T > 0; T--) 
//    {
//        int n;
//        cin >> n;
//        vector<int> L;
//        for (int i = 0; i < n; i++)
//        {
//            int temp;
//            cin >> temp;
//            L.push_back(temp);
//        }
//        int sum=colored_marbles(L,n);
//        cout << sum << endl;
//    }
//    return 0;
//}
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int colored_marbles(vector<int>& L, int n) {
    // Sort the array in descending order
    sort(L.begin(), L.end(), greater<int>());

    // Initialize variables
    int totalSum = 0;
    int lieCount = 0;

    // Iterate through the sorted list
    for (int i = 0; i < n; ++i) {
        int currentnum = L[i];
        int count = 1;

        // Count occurrences of the same color
        while (i + 1 < n && L[i + 1] == currentnum) {
            count++;
            i++;
        }

        // If this is the first time we see this color, add its count to totalSum
        if (lieCount == 0) {
            totalSum += currentnum * ((count - 2) / currentnum + 1);
        }
        else {
            // Otherwise, add the actual count
            totalSum += currentnum * count;
        }

        // Increment lieCount after processing the first group
        lieCount++;
    }

    // Add one more marble for the lie
    totalSum++;

    return totalSum;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<int> L(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i];
        }
        cout << colored_marbles(L, n) << endl;
    }
    return 0;
}
