#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;

const int N = 1e5 + 5;
const int LOG = 18;
int n, q;
vector<pair<int,ll>> a[N];
int pa[N][LOG+1], high[N];
ll mx[N][LOG+1];

struct LCA {
    void dfs(int u, int par, int we) {
        pa[u][0] = par;
        mx[u][0] = we;
        for (auto p : a[u]) {
            int v = p.fi;
            int w = p.se;

            if (v == par) continue;
            high[v] = high[u] + 1;
            dfs(v, u, w);
        }
    }

    void build() {
        dfs(1, 0, 0);
        fors(j, 1, LOG, 1) {
            fors(i, 1, n, 1) {
                pa[i][j] = pa[pa[i][j-1]][j-1];
                mx[i][j] = max(mx[i][j-1], mx[pa[i][j-1]][j-1]);
            }
        }
    }

    ll get(int u, int v) {
        if (high[u] < high[v]) swap(u, v);

        ll ans = 0;
        ford(i, LOG, 0, 1) {
            if (high[pa[u][i]] >= high[v]) {
                ans = max(ans, mx[u][i]);
                u = pa[u][i];
            }
        }

        if (u == v) return ans;

        ford(i, LOG, 0, 1) {
            if (pa[u][i] != pa[v][i]) {
                ans = max({ans, mx[u][i], mx[v][i]});
                u = pa[u][i];
                v = pa[v][i];
            }
        }

        ans = max({ans, mx[u][0], mx[v][0]});
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n-1, 1) {
        int u, v; ll w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }

    LCA lca;
    lca.build();

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.get(u, v) << '\n';
    }
}
