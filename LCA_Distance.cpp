//cho mot cay co n dinh va n-1 canh
//giua hai canh u va v co trong so la w
//q truy van gom hai so u, v
//tim do dai duong di giua u va v

#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int LOG = 17; //  2^16 <= 1e5
int n, q;
vector<pair<int, ll>> a[N];
int pa[N][LOG + 1], high[N];
ll dist[N]; // khoang cach tu dinh i den dinh 1

struct LCA {
    void dfs(int u, int p) {
        pa[u][0] = p;

        for(auto v : a[u]) {
            int x = v.fi;
            ll w = v.se;
            
            if (x != p) {
                high[x] = high[u] + 1;
                dist[x] = dist[u] + w;
                dfs(x, u);
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

    int lca(int u, int v) {
        if (high[u] < high[v]) swap(u, v);

        ford(i, LOG, 0, 1) {
            if (pa[u][i] != 0 && high[pa[u][i]] >= high[v]) {
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

    ll query(int u, int v) {
        int par = lca(u, v);
        return dist[u] + dist[v] - 2*dist[par];
        //duong di tu u den 1, cong duong di tu v den 1
        //tat ca tru cho 2 lan duong di tu lca(u,v) den 1
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
        cout << lca.query(u, v);
        cout << '\n';
    }
}
