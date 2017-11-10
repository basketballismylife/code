#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 7
const int N = 555, M = 1e5 + 10;

struct mincost {
    int n, s, t, E, ans;
    int adj[M], cap[M], flow[M], cost[M], next[M], last[N];
    int best[N], from[N];

    void init(int n, int s, int t) {
        this->n = n; this->s = s; this->t = t;
        fill_n(last, n + 1, -1);
    }
    void add(int u, int v, int co, int ca) {
        adj[E] = v; cap[E] = ca; flow[E] = 0; cost[E] = co; next[E] = last[u]; last[u] = E++;
        adj[E] = u; cap[E] = 0; flow[E] = 0; cost[E] = -co; next[E] = last[v]; last[v] = E++;
    }
    bool findPath() {
        fill_n(best, n + 2, INF);
        best[s] = 0;
        queue <int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id = last[u]; id != -1; id = next[id]) {
                int v = adj[id];
                if (cap[id] > flow[id] && best[u] + cost[id] < best[v]) {
                    best[v] = best[u] + cost[id];
                    q.push(v);
                    from[v] = id;
            //        cerr << id << " " << u << " " << v << "; ";
                }
            }
        }
        return best[t] < INF;
    }
    void incFlow() {
        ans += best[t];
        for (int x = t; x != s; x = adj[from[x] ^ 1]) {
            flow[from[x]]++;
            flow[from[x] ^ 1]--;
          //  cerr << from[x] << " ";
        }
      //  cerr << "\n";
    }
    int run() {
        ans = 0;
        while (findPath()) {
            incFlow();
        }
        return ans;
    }
} mc;

int n, s, t;
int cnt[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    s = n + 1; t = n + 2;
    mc.init(2 * n, s, t);
    int u, v; while (~scanf("%d%d", &u, &v)) {
        mc.add(u, v, 1, INF);
        mc.add(v, u, 1, INF);
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            mc.add(s, i, 0, cnt[i]);
        }
        mc.add(i, t, 0, 1);
    }
}

void process() {
    printf("%d\n", mc.run());
}

int main() {
    freopen("GREED.inp", "r", stdin);
    freopen("GREED.out", "w", stdout);

    load();
    process();

    return 0;
}
