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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;
typedef long double ld;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct point { int u, v; ll w; };
const int N = 2005;
const ll INF = 1e18;
int n, m;
vector<point> a;

bool bell() {
    vector<ll> d(n + 1, 0);

    fors(i, 1, n - 1, 1) {
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
    fors(i, 1, m, 1) {
        int u, v; ll w;
        cin >> u >> v >> w;
        a.pub({u, v, w});
    }

    if (bell()) cout << "YES";
    else cout << "NO";
}
