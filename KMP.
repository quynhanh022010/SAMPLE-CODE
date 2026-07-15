#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

int cnt = 0;

vector<int> get_lps(str p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int len = 0;

    fors(i, 1, m-1, 1) {
        while(len > 0 && p[i] != p[len]) {
            len = lps[len-1];
        }
        if (p[i] == p[len]) len++;
        lps[i] = len;
    }

    return lps;
}

void kmp(str s, str p) {
    int n = s.size();
    int m = p.size();

    vector<int> lps = get_lps(p);
    int j = 0;

    fors(i, 0, n-1, 1) {
        while(j > 0 && s[i] != p[j]) {
            j = lps[j-1];
        }

        if (s[i] == p[j]) j++;
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    str s, t;
    cin >> s >> t;
    kmp(s, t);
}
