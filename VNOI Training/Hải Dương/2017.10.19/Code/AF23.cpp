#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AF23"
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

const int N = 1e6 + 10, MOD = 1e9 + 7;

class FenwickTree {
private:
    int t[N];
public:
    void update(int x, int value) {
        for (; x < N; x += x & -x)
            t[x] = max(t[x], value);
    }
    int get(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x)
            res = max(res, t[x]);
        return res;
    }
} bit;

int n, k;
int a[N];

void load() {
    read(n); read(k);
    FORD(i, n, 1) read(a[i]);
}

void process() {
    int answer = 1;
    FOR(i, 1, n) {
        int pos = bit.get(a[i] - 1);
        answer = 1ll * answer * (!pos ? 1 : i - pos + 1) % MOD;
        bit.update(a[i], i);
    }
    writeln(answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
