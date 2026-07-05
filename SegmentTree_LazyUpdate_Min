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
int n, q;
ll a[N], st[4*N], lazy[4*N];

struct SegmentTree {
    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);

        st[id] = min(st[id*2], st[id*2+1]);
    }

    void push(int id, int l, int r) {
        if (lazy[id] == 0) return;

        int mid = (l + r) / 2;
        st[id*2] += lazy[id];
        lazy[id*2] += lazy[id];

        st[id*2+1] += lazy[id];
        lazy[id*2+1] += lazy[id];

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll val) {
        if (v < l || u > r) return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }

        push(id, l, r);
        int mid = (l + r) / 2;

        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);

        st[id] = min(st[id*2], st[id*2+1]);
    }

    ll get(int id, int l, int r, int u, int v) {
        if (u > r || v < l) return INF;
        if (u <= l && r <= v) return st[id];

        push(id, l, r);
        int mid = (l + r) / 2;

        ll left = get(id*2, l, mid, u, v);
        ll right = get(id*2+1, mid+1, r, u, v);

        return min(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];

    SegmentTree stree;
    stree.build(1, 1, n);

    while(q--) {
        int type, l, r; ll x;
        cin >> type >> l >> r;

        if (type == 1) {
            cin >> x;
            stree.update(1, 1, n, l, r, x);
        } else {
            ll ans = stree.get(1, 1, n, l, r);
            cout << ans << '\n';
        }
    }
}
