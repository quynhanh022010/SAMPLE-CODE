#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N =  1e5 + 10;
const int LOG = 30;
int n, q, a[N];
int nxt[N][LOG + 1];

void prepare()
{
    fors(i, 1, n, 1) nxt[i][0] = a[i];

    fors(j, 1, LOG, 1) {
        fors(i, 1, n, 1) {
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        }
    }
}

int get(int u, int k)
{
    fors(j, 0, LOG, 1) {
        if ((k >> j) & 1) {
            u = nxt[u][j];
        } 
    }
    return u;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];
    prepare();

    while(q--)
    {
        int u, k;
        cin >> u >> k;
        cout << get(u, k) << '\n';
    }
}