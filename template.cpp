

#include <bits/stdc++.h>
#define ll long long
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll findXorinrange(ll x)
{
    ll txor;
    if (x % 4 == 0)
        txor = x;
    else if (x % 4 == 1)
        txor = 1;
    else if (x % 4 == 2)
        txor = x + 1;
    else
        txor = 0;

    return txor;
}

// ordered_set s;
// s.order_of_key(x)  -> no of elements that are lesser than x
// *s.find_by_order(x)  -> x -th largest element in set

//  lcm(x,y)=

//  x= (p1)^a1*(p2)^a2*(p3)^a3*(p4)^a4*(p5)^a5
//  y=(p1)^b1*(p2)^b2*(p3)^b3*(p4)^b4

//  lcm(x,y)==  (p1)^max(a1,b1) * (p2)^max(a2,b2) * (p3)^max(a3,b3)
//  gcd(x,y)==  (p1)^min(a1,b1) * (p2)^min(a2,b2) * (p3)^min(a3,b3)

// important result
// i-th point wala

// gcd of two adjacent ele is 1

class SegmentTree
{

public:
    ll n;
    vector<ll> tree;
    vector<ll> lazy;

    SegmentTree(ll n)
    {
        tree.resize(4000000);
        lazy.resize(4000000, 0);
        this->n = n;
    }

    void build(ll arr[], ll l, ll r, ll node)
    {

        if (l == r)
        {
            tree[node] = arr[l];
            lazy[node] = 0;
            return;
        }

        ll mid = l + (r - l) / 2;

        build(arr, l, mid, 2 * node + 1);
        build(arr, mid + 1, r, 2 * node + 2);

        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]);
        lazy[node] = 0;
    }

    ll query(ll l, ll r, ll st, ll en, ll arr[], ll node)
    {

        if (lazy[node] != 0)
        {

            tree[node] += (en - st + 1) * (lazy[node]);
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (en < l || st > r || st > en)
        {
            return 0;
        }

        if (st >= l && en <= r)
        {
            return tree[node];
        }

        ll mid = st + (en - st) / 2;

        return query(l, r, st, mid, arr, 2 * node + 1) + query(l, r, mid + 1, en, arr, 2 * node + 2);
    }

    void updaterange(ll l, ll r, ll st, ll en, ll arr[], ll node, ll val)
    {

        if (lazy[node] != 0)
        {

            tree[node] += (en - st + 1) * (lazy[node]);
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        // some things i have to propogate

        if (en < l || st > r || st > en)
        {
            return;
        }

        if (st >= l && en <= r)
        {
            tree[node] += ((en - st + 1) * (val));
            if (st != en)
            {

                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        ll mid = st + (en - st) / 2;

        updaterange(l, r, st, mid, arr, 2 * node + 1, val);
        updaterange(l, r, mid + 1, en, arr, 2 * node + 2, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

class DisjointSet
{

public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1, -1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateparent(parent[node]);
    }

    void unionByRank(int u, int v)
    {

        int upar = findUltimateparent(u);
        int vpar = findUltimateparent(v);

        if (findUltimateparent(u) == findUltimateparent(v))
        {
            return;
        }

        if (size[upar] == size[vpar])
        {
            parent[vpar] = upar;
            size[upar]++;
        }

        else if (size[upar] < size[vpar])
        {
            parent[upar] = vpar;
        }

        else
        {
            parent[vpar] = upar;
        }
    }

    bool sameComponent(int u, int v)
    {
        return findUltimateparent(u) == findUltimateparent(v);
    }
};

int main()
{

    DisjointSet d1(4);

    // 1 2 3 4
    d1.unionByRank(1, 2);
    d1.unionByRank(3, 4);
    // d1.unionByRank(4, 1);

    if (d1.sameComponent(2, 3))
    {
        cout << "SAME";
    }
}

what a dsu can do it can find whether two nodes belong to same compo or not based on some condition
                                                                            ultimate parent is used u v ka ultimate parent kya hai

#include <bits/stdc++.h>
#define ll long long
                                                                        using namespace std;

const ll N = 1e9 + 7;
const ll m = 1e9 + 7;

void dfs(vector<ll> adj[], ll node, stack<ll> &s, vector<ll> &vis)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(adj, it, s, vis);
    }

    s.push(node);
}

// dfs for storing in stack

void dfs2(vector<ll> reversed[], ll node, vector<ll> &vis2, vector<ll> &ans, ll arr[])
{

    vis2[node] = 1;

    for (auto it : reversed[node])
    {
        if (!vis2[it])
            dfs2(reversed, it, vis2, ans, arr);
    }

    ans.push_back(arr[node]);
}

// for final answer dfs

int main()
{

    ll n;
    cin >> n;

    ll arr[n + 1];

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> adj[n + 1];
    vector<ll> reversed[n + 1]; // reveresed edges

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        reversed[v].push_back(u);
    }

    stack<ll> s;
    vector<ll> vis(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, i, s, vis);
        }
    }

    vector<ll> vis2(n + 1, 0);
    vector<vector<ll>> scc;

    while (!s.empty())
    {

        ll a = s.top();
        s.pop();

        if (vis2[a] == 0)
        {

            vector<ll> ans;

            dfs2(reversed, a, vis2, ans, arr);

            sort(ans.begin(), ans.end());
            scc.push_back(ans);
        }
    }

    ll ways = 1;
    ll cost = 0;

    //     for (auto it : scc)
    //     {

    //         ll start = it[0];
    //         cost += start;

    //         ll size = it.size();

    //         ll count = 0;

    //         for (ll i = 0; i < size; i++)
    //         {
    //             if (it[i] == start)
    //             {
    //                 count++;
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }

    //         ways = (ways * count) % N;
    //     }

    //     cout << cost << " " << ways << endl;

    //     // real work starts

    //     // reverse all edges
    // }

    // class Solution
    // {
    // public:
    //     int strStr(string haystack, string needle)
    //     {

    //         int n = haystack.size();
    //         int m = needle.size();
    //         if (m > n)
    //         {
    //             return -1;
    //         }

    //         vector<int> lps(m, 0);
    //         int i = 0;
    //         int j = 1;

    //         while (j < m)
    //         {
    //             if (needle[j] == needle[i])
    //             {
    //                 lps[j] = 1 + i;
    //                 j++;
    //                 i++;
    //             }
    //             else
    //             {
    //                 if (i == 0)
    //                 {
    //                     lps[j] = 0;
    //                     j++;
    //                 }
    //                 else
    //                 {
    //                     // make the pointer to the value of lps[i-1]
    //                     int x = lps[i - 1];
    //                     i = x;
    //                 }
    //             }
    //         }

    //         i = 0;
    //         j = 0;

    //         while (i < n && j < m)
    //         {

    //             if (haystack[i] == needle[j])
    //             {
    //                 i++;
    //                 j++;
    //             }
    //             else
    //             {
    //                 if (j == 0)
    //                 {
    //                     i++;
    //                 }
    //                 else
    //                 {
    //                     j = lps[j - 1];
    //                 }
    //             }
    //         }

    //         if (j >= m)
    //         {
    //             return (i - m);
    //         }

    //         return -1;
    //     }
    // };

    // // while making lps array
    // // fix i=0 j=1  and if( same)lps[j]=i+1 i++;j++
    // // else  i==0  lps[j]=0 j++;       i!=0  i=lps[i-1]

    // // move the i backwards

    // // so while mathchig

    // // a[i]==b[j]  i++ j++;
    // // else j==0 i++;
    // // else j!=0 j=lps[j-1]

    const int m1 = 1e9 + 7;

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
        return be(r, m - 2, m) % m;
    }

    vector<int> primefactors(int N)
    {

        vector<int> ans(N + 1, 0);

        for (int i = 2; i * i < N; i++)
        {

            if (ans[i] == 0)
            {
                // i is a prime
                for (int j = i * i; j < N; j += i)
                {
                    ans[j] = 1;
                }
            }
        }

        vector<int> ans1;
        for (int i = 2; i < N; i++)
        {
            if (ans[i] == 0)
            {
                ans1.push_back(i);
            }
        }

        return ans1;
    }

    ll mod_mul(ll a, ll b, ll m)
    {
        a = a % m;
        b = b % m;
        return (((a * b) % m) + m) % m;
    }
    std::vector<ll> fact(1e5 + 1);
    void preCalc(ll m)
    {
        fact[0] = 1;
        for (int i = 1; i <= (1e5); i++)
        {
            fact[i] = mod_mul(fact[i - 1ll], i, m);
        }
    }
    ll binExp(ll a, ll b, ll m)
    {
        ll res = 1, mul = a;
        while (b)
        {
            if (b & 1)
            {
                res = (res * mul) % m;
            }
            mul = (mul * mul) % m;
            b >>= 1;
        }
        return res;
    }
    ll modInv(ll n, ll m)
    {
        return binExp(n, m - 2, m);
    }
    ll nCr(ll n, ll r, ll m)
    {
        ll res = (fact[n] * modInv(fact[r], m)) % m;
        res = (res * modInv(fact[n - r], m)) % m;
        return res % m;
    }
    ll nPr(ll n, ll r, ll m)
    {
        ll res = (fact[n] * modInv(fact[n - r], m)) % m;
        return res;
    }

    // spf--> samllest prime divisor

    // void permute(string &a, set<int> &s, int i, int n)
    // {

    //     if (i >= n)
    //     {
    //         int c = stoi(a);
    //         s.insert(c);

    //         return;
    //     }

    //     for (int j = i; j < n; j++)
    //     {
    //         swap(a[i], a[j]);
    //         permute(a, s, i + 1, n);
    //         swap(a[i], a[j]);
    //     }
    // }
    // string all permutations

    const int m = 100001;
    int arr[m];

    void spf()
    {

        memset(arr, 0, sizeof(arr));
        for (int i = 2; i < m; i++)
        {
            if (arr[i] == 0)
            {
                for (int j = i; j < m; j += i)
                {
                    if (arr[j] == 0)
                        arr[j] = i;
                }
            }
        }
    }
    spf array building-- > to calculate all these prime factors

        int
        main()
    {

        vector<vector<int>> c = {{1, 2}, {2, 4}, {3, 1}};
        sort(c.begin(), c.end(), greater<vector<int>>());

        // q--> jsj  s
    }

    // whenever you can

    // int main()
    // {
    //     auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    //     // insert awesome algorithm here
    //     auto stop = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    //     cerr << "Took " << stop - start << "ms" << endl;
    // }

    //  2 +0

    //   1 4 2 3

    //   1 4 2 3

    //  1+1