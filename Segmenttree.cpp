#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll m1 = 1e9 + 7;

int main()
{

    ll a, N;
    cin >> a >> N;

    queue<ll> q;
    q.push(1);

    vector<ll> vis(N + 1, 0);
    vis[1] = 1;
    ll level = 0;
    bool check = false;

    while (!q.empty())
    {

        ll t = q.size();

        for (ll i = 0; i < t; i++)
        {

            ll no = q.front();
            q.pop();

            if (no == N)
            {
                cout << level;
                check = true;
                break;
            }

            else
            {

                ll newx = a * no;
                if (newx <= N && vis[newx] == 0)
                {
                    vis[newx] = 1;
                    q.push(newx);
                }

                if (no % 10 != 0)
                {
                    // piche se nikal krr aage daldo number mai bss
                    string c = to_string(no);
                    char t = c[c.size() - 1];
                    c.pop_back();
                    c = t + c;

                    ll c1 = stoi(c);

                    if (c1 <= N && vis[c1] == 0)
                    {
                        vis[c1] = 1;
                        q.push(c1);
                    }
                }
            }
        }

        if (check)
        {
            break;
        }

        level++;
    }

    if (!check)
        cout << -1;
}
