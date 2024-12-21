#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll m1 = 1e9 + 7;

// poll to remember
// in case of tle
// use ll
// use"\n"
// make things global
// make arr in dp
// see n*k or k*n thing
// overflow divide by zero for runtime

// start isliye jissse pata chle no start hua bhi hai ya nahi

ll be(ll a, ll b, ll m)
{

    if (b == 0)
        return 1ll;

    ll x = be(a, b / 2, m) % m;
    if (b & 1)
    {
        return (x % m * x % m * a % m) % m;
    }

    return (x % m * x % m) % m;
}

ll invfac(ll r)
{
    return be(r, m1 - 2, m1) % m1;
}

// trie hai

class Trie
{

public:
    Trie *a[2] = {NULL};
    bool end = false;
    ll idx = -1;

    bool hasnext(ll c)
    {
        return (a[c] == NULL);
    }

    void insert(ll bit)
    {
        a[bit] = new Trie();
    }

    Trie *next(ll bit)
    {
        return a[bit];
    }

    void setend()
    {
        this->end = true;
    }
    void setidx(ll idx)
    {
        this->idx = idx;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        Trie *root = new Trie();

        ll n, k;
        cin >> n >> k;
        ll arr[n];

        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        ll maxians = -1;
        ll a = -1;
        ll b = -1;
        ll mymy = -1;

        for (ll j = 0; j < n; j++)
        {

            ll ek = 0;
            ll x = arr[j];
            Trie *node = root;

            if (j > 0)
            {

                for (ll i = k - 1; i >= 0; i--)
                {

                    ll c = ((x & (1ll << i)) > 0);

                    if (!node->hasnext(c))
                    {
                        ll m = 1 - c;
                        // m is bit you want to set if ==1 set else remain  zero
                        if (m == 1)
                        {
                            ek = ek | (1 << i);
                        }
                        node = node->next(c);
                    }

                    else
                    {
                        node = node->next(1 - c);
                    }
                }

                //  cout << ek << endl;

                ll y = arr[node->idx];
                if (((x ^ ek) & (y ^ ek)) > maxians)
                {
                    maxians = ((x ^ ek) & (y ^ ek));

                    a = j + 1;
                    b = node->idx + 1;
                    mymy = ek;
                }
            }

            //  0011
            //  1001

            node = root;
            x = arr[j];

            for (ll i = k - 1; i >= 0; i--)
            {
                ll c = ((x & (1ll << i)) > 0);
                if (node->hasnext(c) == true)
                    node->insert(c);
                node = node->next(c);
            }

            node->setend();
            node->setidx(j);
        }

        // for ends

        cout << min(a, b) << " " << max(a, b) << " " << mymy << endl;

        // cout << maxians << endl;

        // ans
    }
}

//  (0011^1100)&(0001^1000)

//   1111 & 1001
//   1001

// 1111

// (0001^1100)&(0011^1100)

//   1101&1111
//   1101