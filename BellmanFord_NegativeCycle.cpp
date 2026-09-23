#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {int u, v; ll w;};
const int N = 2005;
const ll INF = 1e18;
int n, m;
vector<point> a;

bool bell() {
    vector<ll> d(n + 1, 0);

    for (int i = 1; i <= n- 1; ++i) {
        bool ok = false;
        for (auto t : a) {
            int eu = t.u, ev = t.v;
            ll ew = t.w;

            if (d[ev] > d[eu] + ew) {
                d[ev] = d[eu] + ew;
                ok = true;
            }
        }

        if (!ok) break;
    }

    for (auto t : a) {
        if (d[t.v] > d[t.u] + t.w) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        a.push_back({u, v, w});
    }

    if (bell()) cout << "YES";
    else cout << "NO";
}
