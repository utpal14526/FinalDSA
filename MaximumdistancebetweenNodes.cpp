#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxdistancenode(vector<int> adj[], int n, int node)
{
    int maxidep = -1;
    int maxinode = -1;

    queue<pair<int, int>> q; // queue stores this thing
    q.push({node, 0});
    int dep = 0;

    vector<int> vis(n + 1, 0);
    vis[node] = 1;

    while (!q.empty())
    {

        int node = q.front().first;
        int d = q.front().second;
        if (d > maxidep)
        {
            maxidep = d;
            maxinode = node;
        }

        q.pop();

        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push({it, d + 1});
            }
        }
    }

    return maxinode;
}

pair<int, int> maxdistance(vector<int> adj[], int n)
{
    int maxinode = maxdistancenode(adj, n, 1);
    int mxnodes = maxdistancenode(adj, n, maxinode);
    return {maxinode, mxnodes}; // these are the two nodes composes maximum distance
}

void mxbtnodes(vector<int> adj[], int n, int x, int par, int y, vector<int> &helper, vector<int> &finalans)
{

    if (x == y)
    {
        helper.push_back(x);
        finalans = helper;
        return;
    }

    helper.push_back(x);

    for (auto it : adj[x])
    {
        if (it != par)
        {
            mxbtnodes(adj, n, it, x, y, helper, finalans);
        }
    }

    helper.pop_back();
}

int main()
{

    int n;
    cin >> n;

    vector<int> adj[n + 1]; // adjaceny list
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> p = maxdistance(adj, n);

    int x = p.first;
    int y = p.second;

    vector<int> helper;
    vector<int> finalans;

    mxbtnodes(adj, n, x, -1, y, helper, finalans);

    for (auto it : finalans)
    {
        cout << it << " ";
    }
    cout << endl;
}