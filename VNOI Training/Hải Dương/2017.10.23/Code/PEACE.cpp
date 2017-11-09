#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n, q, lg, par[N], d[N], b[N][20];
vector <int> a[N];

void dfs(int u) {
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v == par[u]) continue;
        par[v] = u;     d[v] = d[u] + 1;
        dfs(v);
    }
}

int get(int u, int v) {
    for (int i = lg; i >= 0; --i)
        if (d[b[u][i]] >= d[v]) u = b[u][i];
    for (int i = lg; i >= 0; --i)
        if (d[b[v][i]] >= d[u]) v = b[v][i];
    if (u == v) return u;
    for (int i = lg; i >= 0; --i)
        if (b[u][i] != b[v][i]) {
            u = b[u][i];    v = b[v][i];
        }
    return par[v];
}

int main(){
    freopen("PEACE.INP", "r", stdin);
    freopen("PEACE.OUT", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int u, v;   scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    lg = log2(n);
    for (int i = 1; i <= n; ++i)
        if (!par[i]) {
            par[i] = i;     d[i] = 1;
            dfs(i);
        }

    for (int i = 1; i <= n; ++i) b[i][0] = par[i];
    for (int j = 1; j <= lg; ++j)
        for (int i = 1; i <= n; ++i) b[i][j] = b[b[i][j-1]][j-1];

    while (q--) {
        int dog, mouse, cat;
        scanf("%d%d%d", &dog, &cat, &mouse);
        int u = get(dog, cat);
        int v = get(cat, mouse);
        int z = get(dog, mouse);
        int res = u;
        if (d[dog] - d[res] > d[dog] - d[v]) res = v;
        if (d[dog] - d[res] > d[dog] - d[z]) res = z;
        printf("%d\n", res);
    }
    return 0;
}
