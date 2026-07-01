#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for(int i=(a); i>=(b); i-=(c))
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;

const int N = 2e5 + 5;
int n, q;
ll a[N], st[4*N];

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

    void update(int id, int l, int r, int k, int u) {
        if (l == r) {
            st[id] = u;
            return;
        }

        int mid = (l + r) / 2;
        if (k <= mid) update(id*2, l, mid, k, u);
        else update(id*2+1, mid+1, r, k, u);

        st[id] = min(st[id*2], st[id*2+1]);
    }

    ll query(int id, int l, int r, int u, int v) {
        if (u > r || v < l) return LLONG_MAX;
        if (u <= l && v >= r) return st[id];

        int mid = (l + r) / 2;
        ll x = query(id*2, l, mid, u, v);
        ll y = query(id*2+1, mid+1, r, u, v);

        return min(x, y);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];

    SegmentTree stree;
    stree.build(1, 1, n);

    while(q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            stree.update(1, 1, n, a, b);
        } else {
            cout << stree.query(1, 1, n, a, b);
            cout << '\n';
        }
    }
}