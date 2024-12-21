

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void quicksort(int arr[], int i, int j)
{
    if (i >= j)
        return;

    //   cout << i << " " << j << endl;

    // make your pivot

    // first element as a pivot

    int pivot = arr[i];
    int st = i + 1;
    int en = j;

    while (st <= en)
    {

        if (arr[st] < pivot)
        {
            st++;
        }
        else
        {
            swap(arr[st], arr[en]);
            en--;
        }
    }

    swap(arr[st - 1], arr[i]);

    quicksort(arr, i, st - 2);
    quicksort(arr, st, j);
}

int main()
{

    // genearte some arr that have

    int n, m;
    cin >> n >> m;

    vector<int> cost(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    map<int, int> mpp;
    int x = cost[1];

    // each cost is aligned with a value

    for (int i = 1; i <= n; i++)
    {
        mpp[cost[i]] = i;
    }

    // for every cost i have a node

    mpp[x] = 1; // for this cost specially i have done this thing

    // each cost got a node

    map<int, int> mpp2;

    for (int i = 1; i <= n; i++)
    {
        int x = cost[i];
        mpp2[i] = mpp[x];
    }

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u = mpp2[u];
        v = mpp2[v];

        //  cout << u << " " << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({cost[1], {1, 1}});

    while (!pq.empty())
    {

        int node = pq.top().second.second;
        int d = pq.top().second.first;

        //  cout << node << " " << d << endl;

        pq.pop();

        if (node == n)
        {
            dp[n] = max(dp[n], d);
            break;
        }

        if (d > dp[node])
            continue;

        for (auto it : adj[node])
        {
            int v = it;
            if (cost[v] > cost[node])
            {
                if ((d + 1) > dp[it])
                {
                    dp[it] = d + 1;
                    pq.push({cost[it], {dp[it], it}});
                }
            }
        }
    }

    cout << dp[n] << endl;
}