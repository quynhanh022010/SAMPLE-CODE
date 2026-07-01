#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = 1e6 + 10;
int n;
ll a[N], dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    fors(i, 1, n, 1) cin >> a[i];

    ll cur = a[1], ans = a[1];
    fors(i, 2, n, 1)
    {
        cur = max(cur + a[i], a[i]);
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}