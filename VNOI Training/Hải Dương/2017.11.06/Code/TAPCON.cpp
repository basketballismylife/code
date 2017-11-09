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
    bool operator == (const vi &a, const vi &b) {
        if (sz(a) != sz(b)) return 0;
        for (int i = sz(a) - 1; i >= 0; --i) if (a[i] != b[i]) return 0;
        return 1;
    }
    vi to_vi(int x) { return vi(1, x); }
}

using namespace bignum;

const int N = 111;

int n, m;
vi p;
int a[N];
vi f[N];

void load() {
    cin >> n;
    f[0] = to_vi(1);
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] + f[i - 1];
}

void query1() {
    vi ans = to_vi(1);
    for (int i = 1; i <= m; ++i) {
        for (int j = a[i - 1] + 1; j < a[i]; ++j)
            ans = ans + f[n - j];
        if (i > 1) ans = ans + to_vi(1);
    }
    cout << ans << "\n";
}

void query2() {
    int x = 1;
    for (int i = 1; i <= n; ++i) {
      //  cout << i << " " << p << " " << f[n - i] << "\n";
        if (p <= f[n - i]) {
            printf("%d ", x);
            p = p - to_vi(1);
        } else {
            p = p - f[n - i];
        }
        x++;
        if (p == to_vi(0)) break;
    }
    puts("");
}

void process() {
    cout << f[n] - to_vi(1) << "\n";
    cin.ignore();
    while (1) {
        string s; getline(cin, s); stringstream ss(s);
        int t;
        if (!(ss >> t)) break;
        if (t == 1) {
            m = 0;
            for (int x; ss >> x;) a[++m] = x;
            query1();
        } else {
            ss >> p;
            query2();
        }
    }
}

int main() {
    freopen("TAPCON.inp", "r", stdin);
    freopen("TAPCON.out", "w", stdout);

    ios_base::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);
    load();
    process();

    return 0;
}
