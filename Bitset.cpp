#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 100005;

int main()
{
    int n, sum;
    cin >> n >> sum;

    bitset<M> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        dp |= (dp << x);
    }

    // itta sa code hai knapsack ka to check if there any sequence exist or not

    cout << dp[sum];

    // some subsequence i there or not i have to know
}

// what it actually doing is

//  1 0 0 0 0 0 0 0 0 0 0  0
//  0 1 2 3 4 5 6 7 8 9 10 11

// when 1 came

//  1 1 0 0 0 0 0 0 0 0 0  0  --> bitset looks like this
//  0 1 2 3 4 5 6 7 8 9 10 11

//  when 4 came
//  1 1 0 0 1 1 0 0 0 0 0  0  --> bitset looks like this
//  0 1 2 3 4 5 6 7 8 9 10 11  --> every bit go by four in right direction

// when 3 came

//  1 1 0 1 1 1 0 1 1 0 0  0  --> bitset looks like this
//  0 1 2 3 4 5 6 7 8 9 10 11

//  when 2 came
//  1 1 1 1 1 1 0 1 1 1 1  0  --> bitset looks like this
//  0 1 2 3 4 5 6 7 8 9 10 11  // these bits i can make surely

set<int> adj[100001]; // for adjancy list
int parent[100001];   // to store parent of each node
int sub[100001];      // to store subtree size

int dfs1(int node, int par)
{
    sub[node] = 1;

    for (auto it : adj[node])
    {
        if (it != par)
        {
            sub[node] += dfs1(it, node);
        }
    }

    return sub[node];
}

int dfs(int node, int par, int n)
{

    for (auto it : adj[node])
    {
        if (it != par && sub[it] > n / 2)
        {
            return dfs(it, node, n);
        }
    }

    return node; // rooted at i find centroid
}

void decompose(int node, int par, vector<char> &ans, char a)
{

    int subtreesize = sub[node];
    int centroid = dfs(node, par, subtreesize);

    parent[centroid] = par;

    ans[node - 1] = a;

    for (auto it : adj[centroid])
    {
        adj[it].erase(centroid);
        decompose(it, centroid, ans, a + 1);
    }
}

int main()
{

    int n;
    cin >> n;

    vector<char> ans(n);

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    dfs1(1, -1);
    decompose(1, -1, ans, 'A');

    for (auto it : ans)
    {
        cout << ans[it] << " ";
    }
}

// centroid tree is like that in answer we have {parent,child} relationship
