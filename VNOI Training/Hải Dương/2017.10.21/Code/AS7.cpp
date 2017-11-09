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
#define task "AS7"
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

struct node {
    int first, second, id;
    node() {}
    node(int f, int s, int i) : first(f), second(s), id(i) {}
    bool operator < (const node &p) { return first < p.first; }
};

int n, answer;
pair <int, int> h[N];
int mark[N];
node a[N];
priority_queue < pair <int, int> > q;

void load() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &h[i].first);
        h[i].second = i;
    }
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].first, &a[i].second);
        a[i].id = i;
    }
}

void process() {
    sort(h + 1, h + n + 1);
    sort(a + 1, a + n + 1);
    int j = n;
    FORD(i, n, 1) {
        while (a[j].first >= h[i].first) {
            q.push({a[j].second, a[j].id});
            j--;
        }
        if (!q.empty()) {
            mark[h[i].second] = q.top().second;
            answer += q.top().first;
            q.pop();
        }
    }
    while (j) {
        q.push({a[j].second, a[j].id});
        j--;
    }
    FOR(i, 1, n) if (!mark[i]) {
        mark[i] = q.top().second;
        q.pop();
    }
    printf("%d\n", answer);
    FOR(i, 1, n) printf("%d ", mark[i]);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
