#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int m, n, p;
int match[N], level[N];
vector <int> adj[N];
vector <int> c;

void load() {
    scanf("%d%d%d", &m, &n, &p);
    while (p--) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
}

bool bfs() {
    queue <int> q;
    for (int i = 1; i <= n; ++i) level[i] = 0;
    for (int x : c) for (int y : adj[x]) if (level[y] == 0) {
        level[y] = 1;
        q.push(y);
    }
    while (!q.empty()) {
        int y = q.front(); q.pop();
        int x = match[y];
        if (!x) return 1;
        for (int v : adj[x]) if (level[v] == 0) {
            level[v] = level[y] + 1;
            q.push(v);
        }
    }
    return 0;
}

bool dfs(int x, int lv) {
    for (int y : adj[x]) if (level[y] == lv) {
        if (match[y] == 0 || dfs(match[y], lv + 1)) {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

void process() {
    for (int i = 1; i <= m; ++i) c.push_back(i);
    int ans = 0;
    while (bfs()) {
        for (int i = c.size() - 1; i >= 0; --i) if (dfs(c[i], 1)) {
            ans++;
            c[i] = c.back();
            c.pop_back();
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("LIGHTING.inp", "r", stdin);
    freopen("LIGHTING.out", "w", stdout);

    load();
    process();

    return 0;
}
