#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "GA11"
#define sqr(x) 1ll * (x) * (x)
#define EPS 1e-9

template <class T> int getBit(T x, int k) { return x >> k & 1; }
template <class T> T onBit(T x, int k) { return x  (T(1) << k); }
template <class T> T offBit(T x, int k) { return x & (~(T(1) << k)); }
template < class T > void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> void write(T x) { if (x / 10) write(x / 10); putchar(x % 10 + '0'); }
template <class T> void writeln(T x) { if (x < 0) putchar('-'); write(abs(x)); putchar('\n'); }

const int N = 3e4 + 10;

int n, m, tail = -1, id, answer;
int num[N], low[N], st[N << 1];
vector < int > a[N];

void load() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u, int p) {
    num[u] = low[u] = ++id;
    for (int v : a[u]) if (v != p) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            st[++tail] = u; st[++tail] = v;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                int x, y, cnt = 1;
                do {
                    y = st[tail--]; x = st[tail--]; cnt++;
                } while (!(x == u && y == v));
                answer = max(answer, cnt);
            }
        }
    }
}

void process() {
    FOR(i, 1, n) if (!num[i])
        dfs(i, -1);
    printf("%d\n", answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
