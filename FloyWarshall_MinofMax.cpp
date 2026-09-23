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

const int N = 305;
const ll INF = 1e18;
int n, m, t;
ll d[N][N];

void reset() {
    fors(i, 1, n, 1) {
        fors(j, 1, n, 1) {
            d[i][j] = INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> t;
    reset();
    fors(i, 1, m, 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }
    

    fors(k, 1, n, 1) {
        fors(i, 1, n, 1) {
            fors(j, 1, n, 1) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min({d[i][j], max(d[i][k], d[k][j])});
                }
            }
        }
    }

    while (t--) {
        int u, v; cin >> u >> v;
        cout << (d[u][v] == INF ? -1 : d[u][v]);
        cout << '\n';
    }
}
