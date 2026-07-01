#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = 3005;
str a, b;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> a >> b;
    a = " " + a; b = " " + b;
    int n = a.size() - 1;
    int m = b.size() - 1;

    fors(i, 1, n, 1)
    {
        fors(j, 1, m, 1)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = m;
    str ans = "";
    while(i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            ans += a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}