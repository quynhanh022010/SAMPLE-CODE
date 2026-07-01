#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = 305;
str s;
int dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> s;
    int n = s.size()-1;
    int ans = 0;
    fors(i, 0, n, 1)
    {
        dp[i] = 1;
        fors(j, 0, i-1, 1)
        {
            if (s[j] <= s[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}