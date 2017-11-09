#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AF25"
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

const int N = 1e5 + 10;

int n, k;
int h[N];
long long sum[N];

void load() {
    read(n); read(k);
    FOR(i, 1, n) read(h[i]);
}

bool ok(int x, long long w) {
    int pos = lower_bound(h + 1, h + n + 1, x) - h;
    return sum[pos] - 1ll * (n - pos + 1) * x >= w;
}

void process() {
    sort(h + 1, h + n + 1);
    FORD(i, n, 1) sum[i] = sum[i + 1] + h[i];
    while (k--) {
        long long w; read(w);
        int l = 0, r = 1e6, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid, w)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        write(ans); putchar(' ');
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
