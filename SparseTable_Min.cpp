#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for(int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

const int N = 1e5 + 5;
const int LOG = 18;
int n, q;
ll st[N][LOG+1];
int lg[N], a[N];

struct SparseTable {
    void build() {
        lg[1] = 0;

        fors(i, 2, n, 1) lg[i] = lg[i>>1] + 1;
        fors(i, 1, n, 1) st[i][0] = a[i];

        fors(j, 1, LOG, 1) {
            fors(i, 1, n - (1<<j) + 1, 1) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    ll get(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];

    SparseTable sta;
    sta.build();

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sta.get(l, r) << '\n';
    }
}
