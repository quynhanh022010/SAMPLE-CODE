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
int n, m;
int a[N], pa[N], sz[N];
vector<tuple<ll, int, int>> vt;

struct DSU {
    void build() {
        fors(i, 1, n, 1) {
            pa[i] = i;
            sz[i] = 1;
        }
    }

    int fin(int x) {
        if (x == pa[x]) return x;
        return pa[x] = fin(pa[x]);
    }

    void unite(int u, int v) {
        u = fin(u);
        v = fin(v);

        if (u != v)  {
            if (sz[u] < sz[v]) swap(u, v);

            pa[v] = u;
            sz[u] += sz[v];
        }
    }
};

DSU dsu;
struct Kruskal {
    void build() {
        ll w;
        int u, v;
        fors(i, 1, m, 1) {
            cin >> u >> v >> w;
            vt.pb({w, u, v}); 
            // trong so - dinh 1 - dinh 2
        }
    }

    ll mst() {
        sort(vt.begin(), vt.end());
        ll ans = 0;

        for (auto t : vt) {
            ll w = get<0>(t);
            int u = get<1>(t);
            int v = get<2>(t);

            if (dsu.fin(u) != dsu.fin(v)) {
                dsu.unite(u, v);
                ans += w;
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Kruskal tree;
    cin >> n >> m;
    
    dsu.build();
    tree.build();
    cout << tree.mst();
}