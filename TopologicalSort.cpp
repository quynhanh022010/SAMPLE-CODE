//do thi co huong n dinh va m canh
//in ra thu tu topo hop ly cua do thi
//de bai dam bao luon co it nhat mot dap an hop le

#include<bits/stdc++.h>
#define fors(i, a, b, c) for(int i=a; i<=b; i+=c)
#define ford(i, a, b, c) for(int i=a; i>=b; i-=c)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, m;
vector<int> a[N];

struct Topo {
    vector<int> indegree() {
        vector<int> ind(n+1);
        fors(i, 1, n, 1) {
            for(int v : a[i]) {
                ind[v]++;
            }
        }
        return ind;
    }

    void sorting() {
        vector<int> ind = indegree();
        queue<int> q;
        vector<int> res;

        fors(i, 1, n, 1) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            res.pb(u);

            for(int v : a[u]) {
                ind[v]--;
                if (ind[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (res.size() != n) {
            cout << -1;
        } else {
            for(int x : res) {
                cout << x << ' ';
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fors(i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }

    Topo topo;
    topo.sorting();
}
