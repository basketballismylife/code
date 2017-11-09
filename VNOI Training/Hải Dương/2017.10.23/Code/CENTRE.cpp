#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 3e4 + 10;

int n, m;
int d[2][N], cnt[2][N];
vector < pair <int, int> > adj[N];

void load() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}

void dijkstra(int s, int id) {
    for (int i = 1; i <= n; ++i) d[id][i] = 1e9 + 7;
    d[id][s] = 0; cnt[id][s] = 1;
    priority_queue < pair <int, int> > q; q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second, du = -q.top().first; q.pop();
        if (du != d[id][u]) continue;
        for (pair <int, int> it : adj[u]) {
            int v = it.second, dv = it.first;
            if (d[id][v] > d[id][u] + dv) {
                d[id][v] = d[id][u] + dv;
                cnt[id][v] = cnt[id][u];
                q.push({-d[id][v], v});
            } else if (d[id][v] == d[id][u] + dv) {
                cnt[id][v] += cnt[id][u];
            }
        }
    }
}

void process() {
    dijkstra(1, 0); dijkstra(n, 1);
    vector <int> ans;
    for (int i = 1; i <= n; ++i) if (d[0][i] + d[1][i] != d[0][n] || cnt[0][n] > cnt[0][i] * cnt[1][i]) {
        ans.push_back(i);
    }
    printf("%d\n", sz(ans));
    for (int v : ans) printf("%d\n", v);
}

int main() {
    freopen("CENTRE.inp", "r", stdin);
    freopen("CENTRE.out", "w", stdout);

    load();
    process();

    return 0;
}
