#include <bits/stdc++.h >
using namespace std;
typedef long long ll;

int main()
{

    int n;
    cin >> n;

    // binary search in a point wali range

    int eps = 1e-2;

    // 0.01
    long double lo = 1;
    long double hi = sqrt(n);

    // 0.000001

    // 2.345  2.346
    // 0.001

    while (hi - lo > eps)
    {

               long double mid = (long double)(hi + lo) / 2.0;

        if (mid * mid < n)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    cout << lo << endl;
}

// till five accuracy you are getting the things
// but how
// what is want

// 0.000001 --> 5 places difference is qual
// 0.000021--> no they not same in five places initial five places
// 0.00000
