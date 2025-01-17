
// no of integers from 1 to n that are coprime with n

// pi(p)=p-1   // p is a prime number
// pi(p^x) = p^x-(p^x/p) (no of numbers that are not coprime with p)    // x>1

// p*p*p*p*p   only some prime factors can divide it for sure
// euler's totient is mutplicative inevres e

// pi(x*y)=pi(x)*pi(y)

// so P(N) --> N can be write  as (p1)^a*(p2)^b*(p3)^c  p1,p2,p3 are primes

//   (p1)^a ka answer i know already
//   (p2)^b  can answer i know already multiple all of them

//   A number can have atmost log2(N) prime factors

//    pi(N)==  pi(p1^a)*pi(p2^b)*pi(p3^c)

//   pi(N)=  (p1^a-(p1^(a-1))) + ....

//  pi(N) ==    p1^(a-1)(p1 -1 )

//  pi(N)  ===    N* ( p1-1)/p1  *(p2-1)/p2

#include <bits/stdc++.h>
using namespace std;

// int main()
// {

//     int n;
//     cin >> n;

//     int cnt = n;

//     for (int i = 2; i * i <= n; i++)
//     {

//         if (n % i == 0)
//         {

//             cnt = cnt / i;
//             cnt = cnt * (i - 1);

//             while (n % i == 0)
//             {
//                 n = n / i;
//             }
//         }
//     }

//     if (n > 1)
//     {

//         cnt = cnt / n;
//         cnt = cnt * (n - 1);
//     }

//     cout << cnt << endl;
// }

//   30  -->   2*3*5

//  10 *

int main()
{

    // you can also use sieve O(lognlogn)

    const int n = 10000;

    int arr[n];

    for (int i = 1; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] == i)
        {
            for (int j = i; j < n; j += i)
            {
                arr[j] = arr[j] / i;
                arr[j] = arr[j] * (i - 1);
            }
        }
    }

    cout << arr[n] << endl; // for a rnage you can get
}