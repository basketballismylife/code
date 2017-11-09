#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, MOD = 1e9 + 7;

int n, m, s, head, tail;
int d[N], cnt[N], st[N];
vector <int> adj[N];

int main() {
    freopen("BFS.inp", "r", stdin);
    freopen("BFs.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &s);
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    head = 0; tail = -1;
    st[++tail] = s; cnt[s] = 1; d[s] = 1;
    while (head <= tail) {
        int u = st[head++];
        for (int v : adj[u]) {
            if (!d[v]) {
                d[v] = d[u] + 1;
                cnt[v] = cnt[u];
                st[++tail] = v;
            } else if (d[v] == d[u] + 1) {
                cnt[v] = (cnt[u] + cnt[v]) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", cnt[i]);
    puts("");

    return 0;
}
