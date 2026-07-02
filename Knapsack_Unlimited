//moi mon do co can nang la w va gia tri la v
//doi voi moi mon do, duoc chon khong gioi han, mien la tong w <= s
//tim gia tri tot nhat co the dat duoc

#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;

const int N = 105;
const int MAXN = 1e5;
int n, s;
int w[N], v[N];
int dp[N][MAXN + 5];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> s;
    fors(i, 1, n, 1) {
        cin >> w[i] >> v[i];
    }


    fors(i, 1, n, 1) {
        dp[0][i] = dp[i][0] = 0;
        fors(j, 1, s, 1) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][s];
}
