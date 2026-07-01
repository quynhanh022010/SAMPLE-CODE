#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for(int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;

const int N = 2e5 + 5;
int n, m;
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

        st[id] = max(st[id*2], st[id*2+1]);
    }

    int query(int id, int l, int r, int val) {
        if (st[id] < val) return 0;
         
        if (l == r) {
            st[id] -= val;
            return l;
        }

        int mid = (l + r) / 2;
        int ans = 0;

        if (st[2*id] >= val) {
            ans = query(id*2, l, mid, val);
        } else {
            ans = query(id*2+1, mid+1, r, val);
        }

        st[id] = max(st[id*2], st[id*2+1]);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fors(i, 1, n, 1) cin >> a[i];
    SegmentTree stree;
    stree.build(1, 1, n);

    fors(i, 1, m, 1) {
        ll x;
        cin >> x;
        int res = stree.query(1, 1, n, x);
        cout << res << '\n';
    }
}