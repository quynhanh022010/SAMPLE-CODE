#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;

const int N = 305;
const int INF = 1e9;
int n, x, y, a[N], b[N];
ll dp[N][N]; 

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("rice.inp", "r", stdin);
    freopen("rice.out", "w", stdout);

    cin >> n >> x >> y;
    fors(i, 1, n, 1) cin >> a[i] >> b[i];

    fors(i, 0, x, 1) {
        fors(j, 0, y, 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    fors(k, 1, n, 1) {
        ford(i, x, 0, 1) {
            ford(j, y, 0, 1) {
                if (dp[i][j] != INF) {
                    int ni = min(x, i + a[k]);
                    int nj = min(y, j + b[k]); 

                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
                }
            }
        }
    } 

    if (dp[x][y] == INF) cout << -1;
    else cout << dp[x][y];
}