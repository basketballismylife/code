#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AS2"
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
template <class T> void writeln(T x) { if (x < 0) putchar('-'); if (x == 0) putchar('0'); else write(abs(x)); putchar('\n'); }

const int N = 1e5 + 10;

int n;
int id[N], p[N], d[N];
bool ok[N];

void load() {
    read(n);
    FOR(i, 1, n) read(p[i]);
    FOR(i, 1, n) read(d[i]);
    FOR(i, 1, n) id[i] = i;
}

void process() {
    sort(id + 1, id + n + 1, [&] (int x, int y) { return d[x] < d[y] || d[x] == d[y] && p[x] < p[y]; });
    int t = 0;
    priority_queue < pair < int, int > > q;
    FOR(i, 1, n) {
        if (t + p[id[i]] <= d[id[i]]) {
            t += p[id[i]];
            ok[id[i]] = 1;
            q.push(make_pair(p[id[i]], id[i]));
        } else {
            if (!q.empty() && t - q.top().first + p[id[i]] <= t) {
                ok[q.top().second] = 0; t -= q.top().first; q.pop();
                t += p[id[i]]; ok[id[i]] = 1; ok[id[i]] = 1;
                q.push(make_pair(p[id[i]], id[i]));
            }
        }
    }
    int cnt = 0;
    FOR(i, 1, n) cnt += !ok[i];
    writeln(cnt);
    FOR(i, 1, n) if (ok[id[i]]) write(id[i]), putchar(' ');
    FOR(i, 1, n) if (!ok[id[i]]) write(id[i]), putchar(' ');
    puts("");
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
