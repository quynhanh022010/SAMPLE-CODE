#include<bits/stdc++.h>
#define fors(i, a, b, c) for (int i=(a); i<=(b); i+=(c))
#define ford(i, a, b, c) for (int i=(a); i>=(b); i-=(c))
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

const int N = 5e5 + 5;
int n, m, cnt, res;
vector<int> a[N];
int num[N], low[N];
stack<int> st;
bool in[N];

void scc(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u); in[u] = true;

    for (int v : a[u]) {
        if (!num[v]) {
            scc(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        res++;
        int tmp = -1;

        while(true) {
            int v = st.top();
            st.pop();

            in[v] = false;
            if (u == v) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fors(i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        //a[v].pb(u);
    }

    fors(i, 1, n, 1) {
        if (!num[i]) scc(i);
    }

    cout << res << '\n';
}
