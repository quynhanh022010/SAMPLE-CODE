#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef string str;

const int base = 257; 
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
str s, t;
ll hs[N], pw[N];

struct Hashing {
    void fact() {
        pw[0] = 1;
        fors(i, 1, N-1, 1) {
            pw[i] = 1LL * pw[i-1] * base % MOD;
        }
    }

    void hsh(str a, int n) {
        fors(i, 1, n, 1) {
            hs[i] = (1LL * hs[i-1] * base + a[i]) % MOD; 
        }
    }

    ll HashT (str a, int m) {
        ll res = 0;
        fors(i, 1, m, 1) {
            res = (res * base + a[i]) % MOD;
        }
        return res;
    }

    ll HashS(int L, int R) {
        ll res = (hs[R] - hs[L-1] * pw[R - L + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> s >> t;
    Hashing Hash;
    
    int n = s.size();
    int m = t.size();
    
    if (m > n) {
        cout << 0 << "\n";
        return 0;
    }

    s = "@" + s;
    t = "@" + t;

    Hash.fact();
    Hash.hsh(s, n);
      
    int cnt = 0;
    fors(i, 1, n - m + 1, 1) {
        if (Hash.HashS(i, i + m - 1) == target) {
            cnt++;
        }
    }

    cout << cnt << "\n";
}
