#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AF24"
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

const int N = 1111;

int n, m;
int a[N][N], v[N], h[N], L[N], R[N];

void load() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) FOR(j, 1, m) read(a[i][j]);
}

void process() {
    long long answer = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            h[j] = (v[j] != a[i][j]) ? 1 : h[j] + 1;
            v[j] = a[i][j];
        }
        stack < int > st;
        FOR(j, 1, m) {
            L[j] = (v[j] != v[j - 1]) ? j : L[j - 1];
            while (!st.empty() && v[j] == v[st.top()] && h[st.top()] <= h[j]) st.pop();
            if (!st.empty()) L[j] = st.top() + 1;
            st.push(j);
        }
        while (!st.empty()) st.pop();
        FORD(j, m, 1) {
            R[j] = (v[j] != v[j + 1]) ? j : R[j + 1];
            while (!st.empty() && v[j] == v[st.top()] && h[st.top()] <= h[j]) st.pop();
            if (!st.empty()) R[j] = st.top() - 1;
            st.push(j);
        }
        cerr << i << "\n";
        FOR(j, 1, m) {
            int w = R[j] - L[j] + 1;
            answer += 1ll * w * (w + 1) / 2 * h[j] * (h[j] + 1) / 2;

        }
    }
    printf("%lld\n", answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
