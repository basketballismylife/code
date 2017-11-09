#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, sz, ans;
int pos[N][N], c[N][N];
char s[N][N];
vector < pair <int, int> > dirt;

void load() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
}

void bfs(int id) {
    bool vis[N][N] = {0};
    int d[N][N];
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = 1e7;
    queue < pair <int, int> > q;
    q.push({dirt[id].first, dirt[id].second});
    vis[dirt[id].first][dirt[id].second] = 1; d[dirt[id].first][dirt[id].second] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for (int i = 0; i < 4; ++i) if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m
                                        && !vis[x + dx[i]][y + dy[i]] && s[x + dx[i]][y + dy[i]] != 'x') {
            d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
            q.push({x + dx[i], y + dy[i]});
            vis[x + dx[i]][y + dy[i]] = 1;
        }
    }
    for (int i = 0; i < (int) dirt.size(); ++i)
        c[id][i] = d[dirt[i].first][dirt[i].second];
}

void findHalmiton(int s, int mask, int dist) {
    if (__builtin_popcount(mask) == sz) {
        ans = min(ans, dist);
        return;
    }
    for (int i = 0; i < sz; ++i) if (!(mask >> i & 1)) {
        findHalmiton(i, mask | (1 << i), dist + c[s][i]);
    }
}

void process() {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (s[i][j] == 'o') {
            dirt.push_back({i, j});
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (s[i][j] == '*') {
            dirt.push_back({i, j});
        }
    }
    sz = (int) dirt.size(); ans = 1e9 + 7;
    for (int i = 0; i < sz; ++i) {
        bfs(i);
       // cerr << dirt[i].first << " " << dirt[i].second << "\n";
    }
    //cerr << sz << "\n";
    //for (int i = 0; i < sz; ++i) for (int j = 0; j < sz; ++j) cerr << i << " " << j << " " << c[i][j] << "\n";
    findHalmiton(0, 1, 0);
    if (ans < 1e6) printf("%d\n", ans); else puts("-1");
}

int main() {
    freopen("MCLEAN.inp", "r", stdin);
    freopen("MCLEAN.out", "w", stdout);

    load();
    process();

    return 0;
}
