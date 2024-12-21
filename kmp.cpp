
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    string p;
    cin >> p;

    int n = p.size();

    int i = 0;
    int j = 1;
    vector<int> lps(n, 0);

    while (j < n)
    {
        if (p[j] == p[i])
        {
            lps[j] = i + 1;
            j++;
            i++;
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }

    vector<int> ans;

    j = n - 1;

    while (j >= 0 && lps[j] > 0)
    {
        ans.push_back(lps[j]);
        j = lps[j] - 1;
    }

    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}