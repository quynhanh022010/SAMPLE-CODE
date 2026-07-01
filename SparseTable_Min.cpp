#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=n; i-=c)
using namespace std;
typedef long long ll;
typedef string str;

const int N = (int) 1e5 + 5;
const int LOG = 18;
int n, q;
int st[N][LOG];
int lg[N], a[N];

void prepare()
{
    lg[1] = 0;
    fors(i, 2, n, 1) lg[i] = lg[i>>1] + 1;
    fors(i, 1, n, 1) st[i][0] = i;

    fors(j, 1, LOG-1, 1) {
        fors(i, 1, n - (1<<j) + 1, 1) {
            int x = st[i][j-1];
            int y = st[i + (1 << (j-1))] [j-1];
            
            if (a[x] <= a[y]) st[i][j] = x;
            else st[i][j] = y;
        }
    }
}

int get_min(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    int x = st[l][k];
    int y = st[r - (1 << k) + 1][k];

    if (a[x] <= a[y]) return x;
    else return y;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    fors(i, 1, n, 1) cin >> a[i];
    prepare();

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get_min(l, r) << '\n';
    }
}