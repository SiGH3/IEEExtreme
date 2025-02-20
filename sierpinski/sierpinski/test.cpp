#include <iostream>
#include <vector>

using namespace std;

vector<long long> Size(31); // Holds sizes of triangles up to step 30

// Function to precompute the sizes of triangles up to step 30
void getSize() {
    Size[1] = 2;
    for (int i = 2; i <= 30; i++) {
        Size[i] = 2 * Size[i - 1] + 1;
    }
}

// Function to determine the color of a point at (x, y)
int getColor(long long x, long long y)
{
    long long s = Size[30]; // Start from the largest triangle size at step 30
    int color = 1; // Start with red (1 for red, 0 for blue)

    // Iterate down through the recursive triangle levels
    while (s >= 2) {
        long long L = (s - 1) / 2;

        if (x <= L) {
            // Point is in the top triangle
            s = L;
        }
        else if (x == L + 1) {
            // Point is in the middle inverted blue triangle
            return 0;
        }
        else {
            // Point is in one of the bottom triangles (left or right)
            x = x - (L + 1);

            if (y <= L - x) {
                // Point is in the left triangle
                s = L;
            }
            else {
                // Point is in the right triangle
                y = y - (L - x);
                s = L;
                color ^= 1; // Toggle color when moving to the right triangle
            }
        }
    }
    return color;
}

int main() {
    getSize();
    int Q;
    cin >> Q;
    long long x, y;
    for (int i = 0; i < Q; i++) 
    {
        cin >> x >> y;
        cout << getColor(x, y) << endl;
    }

    return 0;
}
