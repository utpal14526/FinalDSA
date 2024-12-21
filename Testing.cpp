#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {

        int n = nums.size();

        int dp[n + 1][k + 1];

        int i = 0;
        int j = 0;

        vector<pair<int, int>> p;

        while (j < n)
        {
            if (nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                p.push_back({nums[i], j - i});
                i = j;
            }
        }

        p.push_back({nums[i], j - i});

        n = p.size();

        vector<int> c(n, n);

        map<int, int> mpp;

        for (int i = n - 1; i >= 0; i--)
        {
            if (mpp.find(p[i].first) != mpp.end())
            {
                c[i] = mpp[p[i].first];
            }
            mpp[p[i].first] = i;
        }

        for (auto it : c)
        {
            cout << it << " ";
        }
    }
};

// 5

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution s;
    cout << s.maximumLength(arr, k) << endl;
}
