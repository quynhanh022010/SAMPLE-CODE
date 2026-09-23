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
#define full(a, n) a + 1, a + 1 + n
#define sz(a) (int) (a).size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;
typedef long double ld;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define int long long

const int N = 3e5 + 5;
const ll INF = 1e18;
int n, k;
pll a[N];

ll dist(pii A, pii B) {
    ll fir = abs(1LL * A.fi - B.fi);
    ll sec = abs(1LL * A.se - B.se);
    return fir + sec;
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;
    fors(i, 1, n, 1) cin >> a[i].fi >> a[i].se;

    sort(full(a, n));
    ll best = 1e18;

    set<pll> s;
    s.insert({a[1].se, 1});
    int left = 1;

    priority_queue<ll> pq;
    fors(i, 2, n, 1) {
        while(left < i && abs(a[i].fi - a[left].fi) > best) {
            s.erase({a[left].se, left});
            left++;
        }

        auto it = s.lower_bound({a[i].se - best, -1});

        while(it != s.end() && it->fi <= a[i].se + best) {
            int id = it->se;
            ll kc = dist(a[id], a[i]);

            if (sz(pq) < k) pq.push(kc);
            else if (kc < pq.top()) {
                pq.pop();
                pq.push(kc);
            }

            if (sz(pq) == k) best = pq.top();
            else best = 1e18;

            it++;
        }

        s.insert({a[i].se, i});
    }


    vector<ll> v;
    while(!pq.empty()) {
        ll x = pq.top();
        v.pub(x);
        pq.pop();
    }

    reverse(all(v));
    for (int x : v) cout << x << '\n';
}
