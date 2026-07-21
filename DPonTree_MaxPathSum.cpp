#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef string str;

const int N = 1e5 + 5;
int n;
ll a[N], dp[N], ans = -1e18;
vector<int> adj[N];

void dfs(int u, int pa) {
    dp[u] = a[u];
    ans = max(ans, dp[u]);
    for (int v : adj[u]) {
        if (v == pa) continue;
        
        dfs(v, u);
        ans = max(ans, dp[u] + dp[v]);
        dp[u] = max(dp[u], a[u] + dp[v]);
    }
}
//code khon giai so - code ngu giai hui
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    fors(i, 1, n, 1) cin >> a[i];
    fors(i, 1, n-1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    cout << ans;
}
