#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for (int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef string str;

const int N = 105;
int n, W;
ll w[N], v[N], m[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("anvat.inp", "r", stdin);
    freopen("anvat.out", "w", stdout);

    cin >> n >> W;
    fors(i, 1, n, 1) cin >> v[i] >> w[i] >> m[i];

    vector<pair<ll,ll>> vp;//val - wei
    fors(i, 1, n, 1)
    {
        for(int k=1; k<=m[i]; k*=2)
        {
            vp.pb({k * v[i], k * w[i]});
            m[i] -= k;
        }

        if (m[i] > 0) vp.pb({m[i] * v[i], m[i] * w[i]});
    }

    vector<ll> dp(W+1, 0);
    for(auto p : vp)
    {
        ll val = p.fi;
        ll wei = p.se;
        ford(j, W , wei, 1)
            dp[j] = max(dp[j], dp[j - wei] + val);
    }

    cout << dp[W];
}

