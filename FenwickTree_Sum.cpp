#include<bits/stdc++.h>
#include <cmath>
#define fors(i, a, b, c) for(int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for(int i=(a); i>=(b); i-=(c))
using namespace std;
typedef long long ll;
typedef string str;

const int N = 1e5 + 5;
int n, q;
ll a[N], tree[N];

struct FenwickTree {
    void update(int id, ll val) {
        while(id <= n) {
            tree[id] += val;
            id += id & (-id);
        }
    }

    ll query(int id) {
        int s = 0;
        while(id > 0) {
            s += tree[id];
            id -= id & (-id);
        }
        return s;
    }

    void get(int l, int r) {
        cout << query(r) - query(l-1) << '\n';
    }
};
FenwickTree ft;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];
    fors(i, 1, n, 1) ft.update(i, a[i]);

    while(q--)
    {
        ll type, i, x, l, r;
        cin >> type;
        
        if (type == 1) {
            cin >> i >> x;
            ll diff = x - a[i];
            ft.update(i, diff);
            a[i] = x;
        } else {
            cin >> l >> r;
            ft.get(l, r);
        }
    }
}