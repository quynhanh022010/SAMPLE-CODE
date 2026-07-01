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
int n, q;
ll a[N], tree[N];

struct FenwickTree {
    void update(int id, ll x) {
        while(id <= n) {
            tree[id] ^= x;
            id += id & (-id);
        }
    }

    ll query(int id) {
        int sum = 0;
        while(id > 0) {
            sum ^= tree[id];
            id -= id & (-id);
        }
        return sum;
    }

    void get(int l, int r) {
        cout << (query(r) ^ query(l-1));
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    FenwickTree ft;
    fors(i, 1, n, 1) {
        cin >> a[i];
        ft.update(i, a[i]);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        ft.get(l, r);
    }
}