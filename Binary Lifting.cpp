#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &depth, int par, int node, int dep, vector<vector<int>> &dp)
{

    depth[node] = dep;

    for (auto it : adj[node])
    {
        if (it != par)
        {
            dp[it][0] = node;
            dfs(adj, depth, node, it, dep + 1, dp);
        }
    }
}

int main()
{

    int n, q;
    cin >> n >> q;

    vector<int> adj[n + 1];

    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // make the dp
    vector<int> depth(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(22, -1));

    dfs(adj, depth, -1, 1, 1, dp);

    for (int i = 1; i < 22; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            int par = dp[j][i - 1];
            if (par != -1)
            {
                dp[j][i] = dp[par][i - 1];
            }
        }
    }

    // now queries to answer things

    while (q--)
    {

        int u, v;
        cin >> u >> v;

        int a = v;
        int b = u;
        if (depth[u] > depth[v])
        {
            swap(u, v); // v ka depth bada hai hamesa
        }

        int k = depth[v] - depth[u];

        // k leveles upar lana hai

        int a1 = 0;

        while (k > 0)
        {

            if (k % 2 == 1)
            {
                //  cout << a << endl;
                v = dp[v][a1];
            }

            a1++;
            k /= 2;
        }

        for (int i = 21; i >= 0; i--)
        {

            if (dp[u][i] != dp[v][i])
            {
                v = dp[v][i];
                u = dp[u][i];
            }
        }
        int lca = v;

        if (v == u)
        {
        }
        else
        {

            if (v != 1)
            {
                lca = dp[v][0];
            }
        }

        v = a;
        u = b;

        cout << depth[v] - depth[lca] + depth[u] - depth[lca] << endl;
    }
}
