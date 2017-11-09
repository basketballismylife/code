#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, id;
long long w, sum;
int a[N];
long long f[N], sz[N];
vector <int> adj[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p) {
    sz[u] = a[u];
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        f[u] = max(f[u], sz[v]);
    }
    if (w > max(f[u], sum - sz[u])) {
        w = max(f[u], sum - sz[u]);
        id = u;
    }
}

void process() {
    w = 1e18;
    dfs(1, 0);
    printf("%d\n", id);
}

int main() {
    freopen("HOSPITAL.inp", "r", stdin);
    freopen("HOSPITAL.out", "w", stdout);

    load();
    process();

    return 0;
}
