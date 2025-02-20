#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N;
    cin >> N;

   
   
    if (n <= 0)
    {
        return 0;
    }
    int num = 1;
    while (num < INT_MAX / 3) 
    {
        if (num == n) return true;
                    num *= 3;
                }
                if (num == n) return true;
                return false;
        
    

    if (N < 1)
    {
        cout << -1;
        return 0;
    }

    double logValue = log(N) / log(3);
    if (floor(logValue) == logValue)
    {
        cout << static_cast<int>(logValue);
    }
    else
    {
        cout << -1;
    }
}
