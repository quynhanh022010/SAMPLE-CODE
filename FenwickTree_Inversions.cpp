#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
#define setpr(a) fixed << setprecision(a)
#define rever(a) reverse(a.begin(), a.end())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef string str;

const int N = 1e5 + 5;
const int MOD = 1e8 - 3;
int n;
pair<int,int> a[N], b[N];
int d[N];
ll tree[N];

struct FenwickTree {
    void update(int id, int x) {
        while(id <= n) {
            tree[id] += x;
            id += id & (-id);
        }
    }

    ll query(int id) {
        ll sum = 0;
        while(id > 0) {
            sum += tree[id];
            id -= id & (-id);
        }
        return sum;
    }
};

void nhap(pair<int,int> c[]) {
    fors(i, 1, n, 1) {
        cin >> c[i].fi;
        c[i].se = i;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    nhap(a); nhap(b);
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    
    fors(i, 1, n, 1) d[b[i].se] = a[i].se;
    
    FenwickTree ft;
    ll ans = 0;

    fors(i, 1, n, 1) {
        int val = d[i]; 
        ll inv = (i - 1) - ft.query(val); 
        ans = (ans + inv % MOD + MOD) % MOD;
        ft.update(val, 1);
    }

    cout << ans;
}
