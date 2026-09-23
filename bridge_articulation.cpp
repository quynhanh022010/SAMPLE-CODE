#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fi first
#define se second
#define setpr(a) fixed << setprecision(a)
#define all(a) (a).begin(), (a).end()
#define full(a, sz) a + 1, a + 1 + sz
#define sz(a) (int) (a).size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;
typedef long double ld;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 1e5 + 5;
int n, m, low[N], num[N], timer;
int cau = 0, khop = 0;
vector<int> a[N], res;

void dfs(int u, int p) {
    low[u] = num[u] = ++timer;
    bool check = false;
    int child = 0;

    for (int v : a[u]) {
        if (v == p) continue;

        if (!num[v]) {
            child++;
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) cau++;
            if (p != 0 && low[v] >= num[u]) check = true;
        } else low[u] = min(low[u], num[v]);
    }

    if ((p == 0 && child >= 2) || check) {
        res.pub(u);
        khop++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fors(i, 1, m, 1) {
        int u, v; cin >> u >> v;
        a[u].pub(v);
        a[v].pub(u);
    }

    fors(i, 1, n, 1) {
        if (!num[i]) {
            dfs(i, 0);
        }
    }

    cout << khop << '\n';
    sort(all(res));
    for (int x : res) cout << x << ' ';
}
