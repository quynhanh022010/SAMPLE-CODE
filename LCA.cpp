//cho mot cay co n dinh va n-1 canh
//q truy van gom hai so u, v
//tim to tien chung thap nhat cua u va v trong moi truy van

#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int LOG = 16; //  2^16 <= 1e5
int n, q;
vector<int> a[N];
int pa[N][LOG + 1], high[N];

struct LCA {
    void dfs(int u, int p) {
        pa[u][0] = p;

        for(int v : a[u]) {
            if (v != p) {
                high[v] = high[u] + 1;
                dfs(v, u);
            }
        }
    }

    void build() {
        high[0] = -1;
        dfs(1, 0);
        fors(j, 1, LOG, 1) {
            fors(i, 1, n, 1) {
                pa[i][j] = pa[pa[i][j-1]][j-1];
            }
        }
    }

    int query(int u, int v) {
        if (high[u] < high[v]) swap(u, v);

        ford(i, LOG, 0, 1) {
            if (high[pa[u][i]] >= high[v]) {
                u = pa[u][i];
            }
        }

        if (u == v) return u;

        ford(i, LOG, 0, 1) {
            if (pa[u][i] != pa[v][i]) {
                u = pa[u][i];
                v = pa[v][i];
            }
        }

        return pa[u][0];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n-1, 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    LCA lca;
    lca.build();

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v);
        cout << '\n';
    }
}
