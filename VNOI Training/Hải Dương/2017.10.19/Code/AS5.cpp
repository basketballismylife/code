#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AS5"
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

const int N = 4e5 + 10;

int n, m;
int a[N], lo[N], hi[N], id[2][N];
priority_queue < pair < int, int > > q;
vector < pair < int, int > > result;

void load() {
    read(n); read(m);
    FOR(i, 1, n) {
        read(a[i]);
        id[0][i] = i;
    }
    FOR(i, 1, m) {
        read(lo[i]); read(hi[i]);
        id[1][i] = i;
    }
}

void process() {
    sort(id[0] + 1, id[0] + n + 1, [&](int x, int y) { return a[x] < a[y]; });
    sort(id[1] + 1, id[1] + m + 1, [&](int x, int y) { return lo[x] < lo[y] || lo[x] == lo[y] && hi[x] < hi[y];} );
    int j = 1;
    FOR(i, 1, n) {
        while (j <= m && lo[id[1][j]] <= a[id[0][i]]) {
            q.push({-hi[id[1][j]], id[1][j++]});
        }
        while (!q.empty() && -q.top().first < a[id[0][i]]) q.pop();
        if (!q.empty()) {
            result.push_back({id[0][i], q.top().second});
            q.pop();
        }
    }
    writeln(sz(result));
    REP(i, sz(result)) {
        write(result[i].first); putchar(' '); writeln(result[i].second);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
