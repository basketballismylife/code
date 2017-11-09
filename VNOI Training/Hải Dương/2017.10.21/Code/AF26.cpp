#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())
#define task "AF26"
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

const int N = 1e5 + 10;

int n, q;
int a[N], id[N], pos[N];

void load() {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        id[i] = i;
    }
}

void process() {
    sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] < a[y]; });
    //FOR(i, 1, n) cerr << id[i] << " " << a[id[i]] << "\n";
    FOR(i, 1, n) pos[id[i]] = i;
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        u = pos[u]; v = pos[v];
        if (u > v) swap(u, v);
        int l = u, r = v, ans = 2e9 + 7;
        while (l <= r) {
            int m = (l + r) >> 1;
            ans = min(ans, max(abs(a[id[m]] - a[id[u]]), abs(a[id[m]] - a[id[v]])));
            if (abs(a[id[m]] - a[id[u]]) > abs(a[id[m]] - a[id[v]])) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
