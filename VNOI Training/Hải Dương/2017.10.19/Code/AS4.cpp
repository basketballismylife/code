#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AS4"
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
template <class T> void writeln(T x) { if (x <= 0) putchar((x < 0) ? '-' : '0'); write(abs(x)); putchar('\n'); }

const int N = 1111;

int n, m;
pair <int, int> a[N];

bool cmp(pair <int, int> p, pair <int, int> q) { return p.second - p.first < q.second - q.first || p.second - p.first == q.second - q.first && p.second > q.second; }

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i].first);
    FOR(i, 1, n) scanf("%d", &a[i].second);
    sort(a + 1, a + n + 1, cmp);
    FOR(i, 1, n) if (a[i].second - a[i].first <= m) {
        m += a[i].first;
    }
    printf("%d", m);

    return 0;
}
