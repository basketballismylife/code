#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, s, sum, maxdepth;
vector < pair <int, int> > adj[N];

void load() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i < n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}

void dfs(int u, int p, int depth) {
    maxdepth = max(maxdepth, depth);
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        dfs(it.second, u, depth + it.first);
        sum += 2 * it.first;
    }
}

void process() {
    dfs(s, s, 0);
    printf("%d\n", sum - maxdepth);
}

int main() {
    freopen("ONE.inp", "r", stdin);
    freopen("ONE.out", "w", stdout);

    load();
    process();

    return 0;
}
