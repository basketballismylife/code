#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

namespace bignum {
    typedef vector <int> vi;

    const int MOD = 1e8;

    void fix(vi &a) {
        a.push_back(0);
        for (int i = 0; i < sz(a) - 1; ++i) {
            a[i + 1] += a[i] / MOD; a[i] %= MOD;
            if (a[i] < 0) a[i] += MOD, a[i + 1]--;
        }
        while (!a.back() && sz(a) > 1) a.pop_back();
    }
    vi operator + (const vi &a, const vi &b) {
        vi c = a; c.resize(max(sz(a), sz(b)));
        for (int i = 0; i < sz(b); ++i)
            c[i] += b[i];
        fix(c);
        return c;
    }
    vi operator - (const vi &a, const vi &b) {
        vi c = a;
        for (int i = 0; i < sz(b); ++i)
            c[i] -= b[i];
        fix(c);
        return c;
    }
    bool operator <= (const vi &a, const vi &b) {
        if (sz(a) != sz(b)) return sz(a) < sz(b);
        for (int i = sz(a) - 1; i >= 0; --i) if (a[i] != b[i]) {
            return a[i] < b[i];
        }
        return 1;
    }
    istream& operator >> (istream& cin, vi &a) {
        string s; cin >> s;
        a.resize(sz(s) / 8 + 1);
        for (int i = 0; i < sz(s); ++i) {
            int x = (sz(s) - i - 1) / 8;
            a[x] = a[x] * 10 + s[i] - '0';
        }
        return fix(a), cin;
    }
    ostream& operator << (ostream& cout, const vi &a) {
        printf("%d", a.back());
        for (int i = sz(a) - 2; i >= 0; --i) printf("%08d", a[i]);
        return cout;
    }
    vi to_vi(int x) { return vi(1, x); }
}

using namespace bignum;

const int N = 111;

int n;
vi c[N][N];

void load() {
    scanf("%d", &n);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) c[i][j] = to_vi(0);
    c[n][n] = to_vi(1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n; j > i; --j)
            c[i][j] = c[i + 1][j] + c[i][j + 1];
        c[i][i] = c[i][i + 1];
    }
    cout << c[0][0] << "\n";
}

void query1() {
    int x; scanf("%d", &x);
    vi ans = to_vi(1);
    for (int i = 1, u = 0, v = 0; i <= 2 * n; ++i) {
        int y; scanf("%d", &y);
        if (x < y) {
            ans = ans + c[u + 1][v];
            v++;
        } else {
            u++;
        }
        x = y;
    }
    cout << ans << "\n";
}

void query2() {
    vi p; cin >> p;
    int x = 0; printf("%d ", x);
    for (int i = 1, u = 0, v = 0; i <= 2 * n; ++i) {
        if (p <= c[u + 1][v]) {
            x--; printf("%d ", x);
            u++;
        } else {
            p = p - c[u + 1][v];
            x++; printf("%d ", x);
            v++;
        }
    }
    puts("");
}

void process() {
    int t;
    while (~scanf("%d", &t)) {
        if (t == 1) {
            query1();
        } else {
            query2();
        }
    }
}

int main() {
    freopen("CATALAN.inp", "r", stdin);
    freopen("CATALAN.out", "w", stdout);

    load();
    process();

    return 0;
}
