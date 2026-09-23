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

struct point {
    int x, y;

    bool operator < (const point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

ll dist(point A, point B) {
    ll fir = 1LL * (A.x - B.x) * (A.x - B.x);
    ll sec = 1LL * (A.y - B.y) * (A.y - B.y);
    return fir + sec;
}

const int N = 1e5 + 5;
int n;
vector<point> a;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    fors(i, 1, n, 1) {
        int x, y; cin >> x >> y;
        a.pub({x, y});
    }

    sort(all(a));
    ll best = dist(a[0], a[1]);

    set<pii> s;
    s.insert({a[0].y, 0});

    int left = 0;
    fors(i, 1, n-1, 1) {
        while(left < i && 1LL * (a[i].x - a[left].x) * (a[i].x - a[left].x) > best) {
            s.erase({a[left].y, left});
            left++;
        }

        ll d = sqrtl(best);
        auto it = s.lower_bound({a[i].y - d, -1});

        while (it != s.end() && it->fi <= a[i].y + d) {
            int id = it->se;
            best = min(best, dist(a[i], a[id]));
            it++;
        }

        s.insert({a[i].y, i});
    }

    cout << best;
}
