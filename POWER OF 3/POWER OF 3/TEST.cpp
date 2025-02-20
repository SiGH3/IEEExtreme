#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    int x = 0;
    long long m = 1;
    
    while (m != N)
    {
        m *= 3;
        x++;
        if (m > N)
        {
            x = -1;
            break;
        }
    }
    cout << x;
}