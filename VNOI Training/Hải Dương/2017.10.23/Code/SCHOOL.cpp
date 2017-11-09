#include <bits/stdc++.h>
using namespace std;

const int N = 5555;

int n, m;
int d[N];
long long cnt[N];
vector < pair <int, int> > adj[N];

void load() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int k, u, v, l; scanf("%d%d%d%d", &k, &u, &v, &l);
        adj[u].push_back({l, v});
        if (k == 2) adj[v].push_back({l, u});
    }
}

void process() {
    priority_queue < pair <int, int> > q;
    for (int i = 1; i <= n; ++i) d[i] = (1ll << 31) - 1;
    d[1] = 0; q.push({0, 1}); cnt[1] = 1;
    while (!q.empty()) {
        int u = q.top().second, du = -q.top().first; q.pop();
        if (du != d[u]) continue;

        for (pair <int, int> it : adj[u]) {
            int v = it.second, dv = it.first;
            if (d[v] > d[u] + dv) {
                d[v] = d[u] + dv;
                cnt[v] = cnt[u];
                q.push({-d[v], v});
            } else if (d[v] == d[u] + dv) {
                cnt[v] += cnt[u];
            }
        }
    }
    printf("%d %lld\n", d[n], cnt[n]);
}

int main() {
    freopen("SCHOOL.inp", "r", stdin);
    freopen("SCHOOL.out", "w", stdout);

    load();
    process();

    return 0;
}
