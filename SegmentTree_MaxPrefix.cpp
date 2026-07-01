#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define fi first;
#define se second;
using namespace std;
typedef long long ll;
typedef string str;

const int N = 2e5 + 5;
const ll INF = 1e16;
int n, q;
ll arr[N];

struct node {
    ll sum;
    ll max_prefix;
};
node st[4*N];

node merge(node a, node b) {
    node res;
    res.sum = a.sum + b.sum;
    res.max_prefix = max(a.max_prefix, a.sum + b.max_prefix);
    return res;
}

struct SegmentTree {
    void build(int id, int l, int r) {
        if (l == r) {
            st[id].sum = arr[l];
            st[id].max_prefix = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);

        st[id] = merge(st[id*2], st[id*2+1]);
    }

    void update(int id, int l, int r, int pos, int x) {
        if (l == r) {
            st[id].sum = x;
            st[id].max_prefix = x;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid) update(id*2, l, mid, pos, x);
        else update(id*2+1, mid+1, r, pos, x);

        st[id] = merge(st[id*2], st[id*2+1]);
    }

    node query (int id, int l, int r, int u, int v) {
        if (v < l || u > r) return {0, -INF};
        if (u <= l && r <= v) return st[id];

        int mid = (l + r) / 2;
        node a = query(id*2, l, mid, u, v);
        node b = query(id*2+1, mid+1, r, u, v);

        return merge(a, b);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> arr[i];

    SegmentTree stree;
    stree.build(1, 1, n);

    while(q--) {
        int type, l, r;
        int k, x;

        cin >> type; 
        if (type == 1) {
            cin >> k >> x;
            stree.update(1, 1, n, k, x);
        } else {
            cin >> l >> r;
            node ans = stree.query(1, 1, n, l, r);
            ll res = 0;
            res = max(res, ans.max_prefix);
            cout << res << '\n';
        }
    }
}