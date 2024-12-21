
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// z-function --> calculates the thing like z[i]
// denotes starting with i and 0 how much you can match

// Cses Problemset is just op
// Minimal operation

const int mod = 1e9 + 7;
int base = 33;

int add(int a, int b, int mod)
{
    int res = (a + b) % mod;
    if (res < 0)
        res += mod;
    return res;
}

int mul(int a, int b, int mod)
{
    int res = (a * (1ll) * b) % mod;
    if (res < 0)
        res += mod;
    return res;
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    int x = power(a, b / 2);
    if (b % 2 == 1)
    {
        return (x % mod * x % mod * a % mod) % mod;
    }
    return (x % mod * x % mod) % mod;
}

const int N = 10;

int pw[N];
int inv[N];
int hash1[N];

void precal()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = mul(pw[i - 1], base, mod);
        //  cout << pw[i] << endl;
    }

    inv[0] = 1;
    int pw_inv = power(base, mod - 2);

    for (int i = 1; i < N; i++)
    {
        inv[i] = mul(inv[i - 1], pw_inv, mod);
    }
}

void build(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        hash1[i] = add((i == 0) ? 0 : hash1[i - 1], mul(pw[i], s[i] - 'a' + 1, mod), mod);
    }
}

int getHash(int x, int y)
{

    // x and y are zero based indexing
    int res = add(hash1[y], (x == 0) ? 0 : -hash1[x - 1], mod);
    res = mul(res, inv[x], mod);
    return res;
}