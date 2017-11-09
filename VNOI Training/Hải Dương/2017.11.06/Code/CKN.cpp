#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

namespace bignum {
    const int MOD = 1e8;
    typedef vector <int> vi;
    void fix (vi &a) {
        a.push_back(0);
        for (int i = 0; i < sz(a) - 1; ++i) {
            a[i + 1] += a[i] / MOD; a[i] %= MOD;
            if (a[i] < 0) a[i] += MOD, a[i + 1]--;
        }
        while (!a.back() && sz(a) > 1) a.pop_back();
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
        if (sz(a) != sz(b)) return sz(a) <= sz(b);
        for (int i = sz(a) - 1; i >= 0; --i) if (a[i] != b[i]) return a[i] < b[i];
        return 1;
    }
    vi to_vi(int x) { return vi(1, x); }
}

using namespace bignum;

int n, k;
bool d[111];
vi c[111][111];

void load() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 111; ++i) for (int j = 0; j < 111; ++j) c[i][j] = to_vi(0);
    for (int i = 0; i <= n - k; ++i) c[k][i] = to_vi(1);
    for (int i = k - 1; i >= 0; --i) {
        c[i][n - k] = to_vi(1);
        for (int j = n - k - 1; j >= 0; --j) {
            c[i][j] = c[i + 1][j] + c[i][j + 1];
        }
    }
    cout << c[0][0] << "\n";
}

void query1() {
    memset(d, 0, sizeof d);
    for (int i = 1; i <= k; ++i) {
        int x; scanf("%d", &x);
        d[x] = 1;
    }
    vi ans = to_vi(1);
    for (int i = 1, u = 0, v = 0; i <= n; ++i) {
        if (d[i] == 0) {
            ans = ans + c[u + 1][v];
            v++;
        } else {
            u++;
        }
    }
    cout << ans << "\n";
}

void query2() {
    vi p; cin >> p;
    for (int i = 1, u = 0, v = 0; i <= n; ++i) {
     //   cout << p << " " << c[u + 1][v] << "\n";
        if (p <= c[u + 1][v]) {
            u++;
            printf("%d ", i);
        } else {
            p = p - c[u + 1][v];
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
    freopen("CKN.inp", "r", stdin);
    freopen("CKN.out", "w", stdout);

    load();
    process();

    return 0;
}
