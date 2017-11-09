#include <bits/stdc++.h>
using namespace std;

#define sz(c) (int) c.size()

const int N = 2e5 + 10;

int n, m, q;
long long x[N], y[N], f[N], g[N];
vector < pair <int, int> > adj[N];
pair <long double, int> c[N];

void load() {
    scanf("%d%d%d", &n, &m, &q);
    while (m--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}

void dijkstra(int s, long long d[]) {
    for (int i = 1; i <= n; ++i) d[i] = 1e18;
    priority_queue < pair <long long, int> > q;
    q.push({0, s}); d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second; long long du = -q.top().first; q.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < sz(adj[u]); ++i) {
            int v = adj[u][i].second, dv = adj[u][i].first;
            if (d[v] > d[u] + dv) {
                d[v] = d[u] + dv;
                q.push(make_pair(-d[v], v));
            }
        }
    }
}

void process() {
    dijkstra(1, x);
    dijkstra(n, y);
    for (int i = 1; i <= n; ++i) c[i] = make_pair((long double) y[i] / x[i], i);
    sort(c + 1, c + n + 1);
    f[0] = g[n + 1] = 1e18;
    for (int i = 1; i <= n; ++i) f[i] = min(f[i - 1], x[c[i].second]);
    for (int i = n; i > 0; --i) g[i] = min(g[i + 1], y[c[i].second]);
    while (q--) {
        int a, b; scanf("%d%d", &a, &b);
        long long ans = 1e18;
        long double t = (long double) a / b;
        pair <long double, int> p;
        p.first = t;
        int id = lower_bound(c + 1, c + n + 1, p) - c;
        ans = min(a * f[id - 1], b * g[id]);
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("MEETINGPOINT.inp", "r", stdin);
    freopen("MEETINGPOINT.out", "w", stdout);

    load();
    process();

    return 0;
}
