#include <bits/stdc++.h>
using namespace std;

const int N = 333;

int n, num;
int vis[N];
int match[N], s[N][N], ans[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)  for (int j = 1; j <= n; ++j) scanf("%d", &s[i][j]);
}

bool dfs(int u, int x) {
    if (vis[u] != num) vis[u] = num; else return 0;
    for (int v = 1; v <= n; ++v) if (s[u][v] >= x && match[v] != u) {
        if (!match[v] || dfs(match[v], x)) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

bool ok(int x) {
    num = 0;
    memset(match, 0, sizeof match);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        num++;
        if (!dfs(i, x)) return 0;
    }
    for (int i = 1; i <= n; ++i) ans[match[i]] = i;
    return 1;
}

void process() {
    int l = 0, r = 20000, res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}

int main() {
    freopen("NANGSUAT.inp", "r", stdin);
    freopen("NANGSUAT.out", "w", stdout);

    load();
    process();

    return 0;
}
