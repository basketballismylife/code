#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

template <class T> void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') nega = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> wri(T x) { if (x / 10) wri(x / 10); putchar(x % 10 + '0'); }
template <class T> write(T x) { if (x < 0) putchar('-'); wri(abs(x)); }
template <class T> writeln(T x) { write(x); putchar('\n'); }

const int N = 1e5 + 10;

int m, n, p, t;
int match[N], level[N];
vector <int> xlist;
vector <int> adj[N];
bool found;

void load() {
    read(m); read(n); read(p);
    while (p--) {
        int u, v; read(u); read(v);
        adj[u].push_back(v);
    }
}

bool BFS() {
    queue <int> q;
    for (int i = 1; i <= n; ++i) level[i] = 0;
    for (int x : xlist) for (int y : adj[x]) if (level[y] == 0) {
        level[y] = 1;
        q.push(y);
    }
    while (!q.empty()) {
        int y = q.front(); q.pop();
        int x = match[y];
        if (x == 0) return 1;
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
    for (int i = 1; i <= m; ++i) xlist.push_back(i);
    int res = 0;
    while (BFS()) {
        for (int i = sz(xlist) - 1; i >= 0; --i) {
            if (dfs(xlist[i], 1)) {
                ++res;
                xlist[i] = xlist.back();
                xlist.pop_back();
            }
        }
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i)
        printf("%d ", match[i]);
}

int main() {
    freopen("ASSIGN.inp", "r", stdin);
    freopen("ASSIGN.out", "w", stdout);

    load();
    process();

    return 0;
}
