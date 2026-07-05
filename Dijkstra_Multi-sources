//Source: Bai 2 MarisaOJ, phan BFS/Dijkstra da luong
//do thi vo huong co trong so gom n dinh va m duong di
//moi dinh co mot loai nguyen lieu rieng, tong se co k nguyen lieu
//tim vi tri dat nha hang de tong trong so khi mua du k nguyen lieu la nho nhat

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
const ll INF = 1e18;
int n, m, k, a[N];
vector<pair<int,ll>> adj[N];

vector<ll> dij(vector<int> &v) {
    vector<ll> d(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    for (auto x : v) {
        d[x] = 0;
        pq.push({0, x});
    }

    while(!pq.empty()) {
        pair<ll,int> p = pq.top();
        pq.pop();

        int u = p.se;
        ll dist = p.fi; 

        if (dist > d[u]) continue;
        for (auto pr : adj[u]) {
            int v = pr.fi;
            ll w = pr.se;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> k;
    fors(i, 1, n, 1) cin >> a[i];
    fors(i, 1, m, 1) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<vector<int>> v(k + 1);
    fors(i, 1, n, 1) {
        v[a[i]].pb(i);
    }

    vector<vector<ll>> d(k + 1);
    fors(c, 1, k, 1) {
        d[c] = dij(v[c]);
    }

    int ans = -1;
    ll mi = INF;

    fors(i, 1, n, 1) {
        ll sum = 0;
        bool ok = true;
        fors(c, 1, k, 1) {
            if (d[c][i] == INF) {
                ok = false;
                break;
            }
            sum += d[c][i];
        }
        if (ok && sum < mi) {
            mi = sum;
            ans = i;
        }
    }

    cout << ans << "\n";
}
