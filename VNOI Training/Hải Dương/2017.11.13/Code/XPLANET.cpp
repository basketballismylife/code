#include <bits/stdc++.h>
using namespace std;

const int N = 222;

int n, ans;
bool ok;
int a[N][N], c[N];
bool mark[N], x[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 3; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
        a[i][i] = 1; c[i] = 1 - c[i];
    }
}

void swapRow(int u, int v) {
    for (int i = 1; i <= n; ++i) swap(a[u][i], a[v][i]);
    swap(c[u], c[v]);
}

void addRow(int u, int v) {
    for (int i = 1; i <= n; ++i) a[u][i] = (a[u][i] + a[v][i]) % 2;
    c[u] = (c[u] + c[v]) % 2;
}

void gauss() {
    for (int i = 1; i <= n; ++i) {
        int u = i;
        while (u <= n && a[u][i] == 0) u++;
        if (u <= n) {
            swapRow(u, i);
            for (u = i + 1; u <= n; ++u) if (a[u][i] == 1) {
                addRow(u, i);
            }
        }
    }
}

void xuly() {
    int t = 0;
    for (int i = 1; i <= n; ++i) t += x[i];
    if (t < ans) {
        ans = t;
        for (int i = 1; i <= n; ++i) mark[i] = x[i];
    }
}

void thu(int k) {
    if (k == 0) { ok = 1; xuly(); return; }
    int t = 0;
    for (int j = k + 1; j <= n; ++j) t = (t + a[k][j] * x[j]) % 2;
    t = (c[k] - t + 2) % 2;
    if (a[k][k] == 1) {
        x[k] = t;
        thu(k - 1);
        return;
    }
    if (t == 1) return;
    for (int j = 0; j < 2; ++j) {
        x[k] = j;
        thu(k - 1);
    }
}

void process() {
    ans = 1e9;
    gauss();
    thu(n);
    if (!ok) puts("-1"); else {
        printf("%d\n", ans);
        for (int i = 1; i <= n; ++i) if (mark[i]) printf("%d\n", i);
    }
}

int main() {
    freopen("XPLANET.inp", "r", stdin);
    freopen("XPLANET.out", "w", stdout);

    load();
    process();

    return 0;
}
