//n dinh, n-1 canh, tat ca cac dinh co gia tri la 0
//hai truy van: 1 u v (tang tat ca cac dinh trong cay con goc u len v); 2 u (tinh gia tri cua cay con goc u)
//in ra ket qua cua cac truy van loai 2

#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, q;
int tin[N], tout[N], tg;
ll tree[N];
vector<int> a[N];

void dfs(int u, int p) {
    tin[u] = ++tg;
    for(int v : a[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = tg;
}

struct FenwickTree {
    void update(int id, ll x) {
        while(id <= n + 1) {
            tree[id] += x;
            id += id & (-id);
        }
    }

    ll query(int id) {
        ll sum = 0;
        while(id > 0) {
            sum += tree[id];
            id -= id & (-id);
        }
        return sum;
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
    dfs(1, 0);

    FenwickTree ft;
    while(q--) {
        int type, u, v;
        cin >> type;

        if (type == 1) {
            cin >> u >> v;
            ft.update(tin[u], v);
            ft.update(tout[u] + 1, -v);
        } else {
            cin >> u;
            cout << ft.query(tin[u]) << '\n';
        }
    }
}
