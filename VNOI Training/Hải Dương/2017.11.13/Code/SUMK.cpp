#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (long i = a; i <= b; ++i)
#define FORD(i, b, a) for (long i = b; i >= a; --i)
#define REP(i, n) for (long i = 0; i < n; ++i)
#define REPD(i, n) for (long i = n - 1; i >= 0; --i)
#define FORE(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

#define sz(v) (long) v.size()
#define fi first
#define se second
#define all(v) v.begin(), v.end()

#define sqr(x) ((x) * (x))
#define EPS 1e-9
#define INF 2e9
#define long long long

const int base = 1e9 + 7;

int n, k;
int c[55][55];

struct matrix {
    long a[55][55];
    matrix operator * (const matrix &p) {
        matrix c;
        FOR(i, 1, k + 2) FOR(j, 1, k + 2) {
            c.a[i][j] = 0;
            FOR(v, 1, k + 2) c.a[i][j] = (c.a[i][j] + this->a[i][v] * p.a[v][j] % base) % base;
        }
        return c;
    }
    void init() { REP(i, 55) REP(j, 55) a[i][j] = i == j; }
};

matrix a;

matrix power(matrix a, int k) {
    matrix c; c.init();
    while (k) {
        if (k & 1) c = c * a;
        a = a * a;
        k >>= 1;
    }
    return c;
}

void calc() {
    REP(i, k + 3) REP(j, k + 3) a.a[i][j] = 0;
    FOR(i, 1, k + 1)
        FOR(j, 1, i) a.a[i][j] = c[i - 1][j - 1];
    FOR(j, 1, k + 1) a.a[k + 2][j] = a.a[k + 1][j];
    a.a[k + 2][k + 2] = 1;

    long ans = 0;
    if (n == 1)
        ans = 1;
    else {
        matrix c = power(a, n - 1);
        FOR(i, 1, k + 2) ans = (ans + c.a[k + 2][i]) % base;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("SUMK.inp", "r", stdin);
    freopen("SUMK.out", "w", stdout);

    c[0][0] = 1;
    FOR(i, 1, 50) REP(j, i + 1) c[i][j] = (c[i - 1][j] + (j > 0) * c[i - 1][j - 1]) % base;

    int t; scanf("%d", &t);
    while (t--) {
        n, k; scanf("%d%d", &n, &k);
        calc();
    }

    return 0;
}
