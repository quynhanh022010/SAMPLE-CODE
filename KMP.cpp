#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i?=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    str s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();

    vector<int> lps(m, 0);
    fors(i, 1, m-1, 1) {
        int j = lps[i-1];
        while(j > 0 && p[i] != p[j]) j = lps[j-1];
        if (p[i] == p[j]) j++;
        lps[i] = j;
    }

    int cnt = 0, j = 0;
    fors(i, 0, n-1, 1) {
        while(j > 0 && s[i] != p[j]) j = lps[j-1];
        if (s[i] == p[j]) j++;
        if (j == m) {
            cnt++;
            j = lps[j-1];
        }
    }

    cout << cnt;
}
