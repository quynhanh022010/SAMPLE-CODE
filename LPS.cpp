#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = 2005;
str a;
bool dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> a; 
    a = " " + a;
    int n = a.size() - 1;

    fors(i, 1, n, 1) dp[i][i] = true;
    fors(i, 1, n-1, 1) dp[i][i+1] = (a[i] == a[i+1]);

    fors(len, 3, n, 1)
    {
        fors(i, 1, n - len + 1, 1)
        {
            int j = i + len - 1;
            dp[i][j] = ((a[i] == a[j]) && dp[i+1][j-1]); 
        }
    }

    int q;
    cin >> q; 
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[l][r] ? "YES\n" : "NO\n");
        //cout << a.substr(l, r - l + 1);
    }
}