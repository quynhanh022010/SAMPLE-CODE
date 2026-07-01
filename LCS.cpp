#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = 3005;
int n;
ll a[N], b[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
	fors(i, 1, n, 1) cin >> a[i];
	fors(i, 1, n, 1) cin >> b[i];

    fors(i, 1, n, 1)
    {
        fors(j, 1, n, 1)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][n] << '\n';
}