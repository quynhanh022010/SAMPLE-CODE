#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define full(a, sz) a + 1, a + 1 + sz
#define sz(a) (int) (a).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 2e5 + 5;
int n, m, num[N], low[N], timer, res;
stack<int> st;
vector<pii> a[N];

void dfs(int u, int pa) {
    num[u] = low[u] = ++timer;
    st.push(u); //neu la BCC dinh

    for (auto p : a[u]) {
        int v = p.fi, id = p.se;
        if (id == pa) continue;

        if (!num[v]) {
            //st.push(id) neu la BCC canh
            dfs(v, id);
            low[u] = min(low[u], low[v]);

            if (low[v] >= num[u]) {
                int cnt = 1; //dem so dinh trong BCC, da tinh san dinh u
                while(true) {
                    int x = st.top();
                    st.pop();

                    cnt++;
                    if (x == v) break;
                }
                res = max(res, cnt);
            }
        } else low[u] = min(low[u], num[v]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fors(i, 1, m, 1) {
        int u, v; cin >> u >> v;
        a[u].pub({v, i});
        a[v].pub({u, i});
    }

    if (m == 0) {
        cout << n;
        return 0;
    }

    fors(i, 1, n, 1) {
        if (!num[i]) {
            dfs(i, -1);
        }
    }

    cout << res;
}
