#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// decide your block size BLK  is my block size

vector<int> mpp(1000001, 0);
int cnt = 0;

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int BLK = sqrt(n);

    int q;
    cin >> q;

    vector<pair<pair<int, int>, int>> p;
    vector<int> ans(q, 0);

    int i = 0;

    while (q--)
    {

        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p.push_back({{a, b}, i});
        i++;
    }
    // query in zero based indexing

    sort(p.begin(), p.end(), [BLK](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
         {
             if (a.first.first / BLK != b.first.first / BLK)
             {
                 return a.first.first < b.first.first;
             }
             else
             {
                 return a.first.second <= b.first.second;
             } });

        int st = 0;
    int en = -1;

    for (int i = 0; i < p.size(); i++)
    {

        int x = p[i].first.first;
        int y = p[i].first.second;

        int o = p[i].second;

        // obv x<=y

        while (en < y)
        {
            en++;
            mpp[arr[en]]++;
            if (mpp[arr[en]] == 1)
            {
                cnt++;
            }
        }
        // include your range

        while (en > y)
        {

            mpp[arr[en]]--;
            if (mpp[arr[en]] == 0)
                cnt--;

            en--;
        }

        while (st > x)
        {
            st--;
            mpp[arr[st]]++;
            if (mpp[arr[st]] == 1)
                cnt++;
        }
        // include your range

        while (st < x)
        {

            mpp[arr[st]]--;
            if (mpp[arr[st]] == 0)
                cnt--;
            st++;
        }

        ans[o] = cnt;
    }

    for (auto it : ans)
    {
        cout << it << endl;
    }
}
