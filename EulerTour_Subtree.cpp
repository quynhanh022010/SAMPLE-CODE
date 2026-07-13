//n dinh, n-1 canh
//ban dau tat ca cac dinh deu co gia tri la 0
//voi moi truy van u x, tat ca cac dinh trong cay con goc se += x
//in ra gia tri cua cac dinh trong cay sau moi truy van

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
int tin[N], tout[N], tg, diff[N];
int ans[N];
vector<int> a[N];

void dfs(int u, int p) {
    tin[u] = ++tg;
    for(int v : a[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = tg;
}

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
    fors(i, 1, q, 1) {
        int u; ll x;
        cin >> u >> x;
        diff[tin[u]] += x;
        diff[tout[u] + 1] -= x;
    }

    fors(i, 1, n, 1) {
        ans[i] = ans[i-1] + diff[i];
    }

    fors(i, 1, n, 1) {
        cout << ans[tin[i]] << ' ';
    }
}
