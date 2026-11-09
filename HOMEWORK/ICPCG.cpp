#include <bits/stdc++.h>
#define f(a, b, c) for (ll a = b; a <= c; a++)
#define all(x) x.begin(), x.end()
#define ll long long
#define file(f)                         \
    if (fopen((f ".inp"), "r"))         \
    {                                   \
        freopen(f ".inp", "r", stdin);  \
        freopen(f ".out", "w", stdout); \
    }
using namespace std;
const int N = 1e6 + 5;

ll n, i, t, j, f[N], d, Max, ans, f1[N];
map<ll, ll> mp;
string s;

int main()
{
    file("test");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s;
        ll len = s.length();
        fill(f, f + len + 2, 0);
        fill(f1, f1 + len + 2, 0);
        i = j = 0;
        mp.clear();
        d = 1;
        Max = -1e18;
        f[1] = s.length();
        while (j != s.length())
        {
            j++;
            if (s[i] != s[j])
            {
                i = j;
                if (d != 1)
                {
                    f[d]++;
                }
                Max = max(Max, d);
                d = 1;
            }
            else
            {
                d++;
            }
        }

        if (Max != 1)
        {
            f[Max]--;
            if (Max / 2 > 1)
            {
                f[Max / 2]++;
            }
            if (Max - Max / 2 - 1 > 1)
            {
                f[Max - Max / 2 - 1]++;
            }
        }
        f(i, 1, s.length())
        {
            if (f[i] != 0)
            {
                mp.insert(make_pair(i, f[i]));
            }
        }
        f1[1] = s.length();
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans = 0;
            f(j, 2, it->first)
            {
                f1[j] += ((it->first - j) + 1) * it->second;
            }
        }
        f(i, 1, s.length())
        {
            cout << f1[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
