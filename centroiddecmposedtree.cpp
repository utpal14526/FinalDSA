#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 20;
int n;
char res[N];
vector<int> g[N];
int parent[N];

// n is the number of nodes   each time clear them for new test cases

void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void output()
{
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int sz[N];
bool dead[N];

void pre_dfs(int v, int par = -1)
{
    sz[v] = 1;
    for (int u : g[v])
    {
        if (u == par || dead[u])
            continue;
        pre_dfs(u, v);
        sz[v] += sz[u];
    }
}

int find_centroid(int num, int v, int par = -1)
{
    for (int u : g[v])
        if (u != par && !dead[u] && 2 * sz[u] > num)
            return find_centroid(num, u, v);
    return v;
}

void solve(int v, char current_char, int par)
{
    pre_dfs(v);
    int cent = find_centroid(sz[v], v);

    res[cent] = current_char;
    dead[cent] = true;

    parent[cent] = par; // parent of this cent is par

    // for this centroid i can have some parent feature

    for (int u : g[cent])
        if (!dead[u])
            solve(u, current_char + 1, cent);
}

int main()
{
    input();

    solve(0, 'A', -1);

    output();
}
