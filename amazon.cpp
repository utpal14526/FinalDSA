#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {

        ll x1, y1, z1, x2, y2, z2, k;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> k;

        ll p1 = abs(x1 - x2);
        ll p2 = abs(y1 - y2);
        ll p3 = abs(z1 - z2);

        ll a1 = p1;
        ll b1 = p2;
        ll c1 = p3;

        if (p1 > p2)
        {
            swap(p1, p2);
            if (p2 > p3)
            {
                swap(p2, p3);
            }
        }

        if (p1 > p2)
        {
            swap(p1, p2);
        }

        if (p2 == p3)
        {
            cout << a1 + b1 + c1 << endl;
        }

        else
        {

            ll dis = p3 - p2;
            ll k1 = dis / k;
            if (dis % k == 0)
                k1--;

            if (k1 <= p1)
            {
                cout << a1 + b1 + c1 << endl;
            }
            else
            {
                ll cnt = p1;
                p3 = p3 - (p1 + 1) * k;
                cnt += ((p1 + 1) * k);

                p1 = 0;

                ll c = p2 * k;

                if (c >= p3)
                {
                    cout << a1 + b1 + c1 << endl;
                }
                else
                {

                    cnt += p2;
                    cnt += (p2 * k);

                    p3 = p3 - (p2 * k);
                    ll see = (p3 / k);
                    if (p3 % k != 0)
                    {
                        see++;
                    }

                    cnt += see;
                    cout << cnt + p3 << endl;
                }
            }
        }
    }
}
