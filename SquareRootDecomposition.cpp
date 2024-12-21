#include <bits/stdc++.h>
using namespace std;

int getMin(vector<int> &F, int arr[], int n, int l, int r)
{

    int BLK = sqrt(n);

    int LB = l / BLK;
    int RB = r / BLK;

    int mn = INT_MAX;

    // block of two ranges

    if (LB == RB)
    {
        // within same block O(sqrt(n))--> mai answer

        for (int i = l; i <= r; i++)
            mn = min(mn, arr[i]);
        return mn;
    }

    for (int i = l; i < (BLK * (LB + 1)); i++)
    {
        mn = min(mn, arr[i]);
    }

    // 0 1 2 3 4 5 6 7 8

    for (int i = LB + 1; i < RB; i++)
    {
        mn = min(mn, F[i]);
    }

    for (int i = (RB * BLK); i <= r; i++)
    {

        mn = min(mn, arr[i]);
    }

    return mn;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int block = sqrt(n); // block of square root size

    // square root ke blocks bnege
    // somebody asks me to find the max in the range
    // make the F array
    int no = (n + block - 1) / block;

    vector<int> F(no, INT_MIN);

    for (int i = 0; i < n; i += block)
    {

        // iss block ka min nikal lo
        int mini = arr[i];
        int j = i;
        int cnt = block;

        while (j < n && cnt > 0)
        {
            mini = min(mini, arr[j]);
            j++;
            cnt--;
        }

        F[i / block] = mini;
    }

    cout << getMin(F, arr, n, 3, 8);
}

// and that's how we make root(n) size blocks and precalculate it
// that blocks mai batne wali chiche we can do it in Mo's algorithm
// anyone in the range try to find according to some value