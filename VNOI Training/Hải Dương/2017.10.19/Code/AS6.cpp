#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "AS6"
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

const int N = 1e4 + 10;

int n;
pair < int, int > a[N];

void load() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &a[i].first, &a[i].second);
}

void process() {
    sort(a + 1, a + n + 1, [&](pair < int, int > p, pair < int, int > q) { return p.second < q.second; });
   // FOR(i, 1, n) cerr << a[i].first << " " << a[i].second << "\n";
    priority_queue < int > q;
    int answer = 0, t = 0;
    FOR(i, 1, n) {
        if (t < a[i].second) {
            answer += a[i].first;
            q.push(-a[i].first);
            t++;
        } else if(-q.top() < a[i].first) {
            answer += a[i].first + q.top();
            q.pop(); q.push(-a[i].first);
        }
    }
    printf("%d\n", answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
