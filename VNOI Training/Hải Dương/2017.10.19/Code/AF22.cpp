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
#define task "AF22"
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

const int N = 257;

int n, K;
int sum[N][N][N];

void load() {
    scanf("%d%d", &n, &K);
    REP(love, n) {
        int i, j, k; scanf("%d%d%d", &i, &j, &k); i++; j++; k++;
        sum[i][j][k]++;
    }
}

inline int get_sum(int i1, int j1, int k1, int i2, int j2, int k2) {
    return sum[i2][j2][k2] - sum[i1 - 1][j2][k2] - sum[i2][j1 - 1][k2] - sum[i2][j2][k1 - 1]
            + sum[i1 - 1][j1 - 1][k2] + sum[i1 - 1][j2][k1 - 1] + sum[i2][j1 - 1][k1 - 1]
            - sum[i1 - 1][j1 - 1][k1 - 1];
}

inline bool ok(int x) {
    FOR(i, x + 1, 256) FOR(j, x + 1, 256) FOR(k, x + 1, 256) {
        int cur = get_sum(i - x, j - x, k - x, i, j, k);
        if (cur >= K) return 1;
    }
    return 0;
}

void process() {
    FOR(i, 1, 256) FOR(j, 1, 256) FOR(k, 1, 256) {
        sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1]
                        - sum[i - 1][j - 1][k] - sum[i - 1][j][k - 1] - sum[i][j - 1][k - 1]
                        + sum[i - 1][j - 1][k - 1];
    }
    int l = 1, r = 255, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
