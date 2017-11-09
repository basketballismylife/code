#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

typedef vector <long long> vi;

const int MOD = 1e8;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < sz(a); ++i) {
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

vi to_vi(int x) { return vi(1, x); }

ostream& operator << (ostream& cout, const vi &a) {
    printf("%lld", a.back());
    for (int i = sz(a) - 2; i >= 0; --i) printf("%08lld", a[i]);
    return cout;
}

const int N = 5200;

int n, m;
vi f[110][N];

void load() {
    scanf("%d%d", &n, &m);
}

void process() {
    for (int i = 0; i < 111; ++i) for (int j = 0; j < N; ++j)
        f[i][j] = to_vi(0);
    f[0][0] = to_vi(1);
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= n * (n + 1) / 2; ++j)
        f[i][j] = f[i - 1][j] + f[i - 1][j + i] + f[i - 1][abs(j - i)];
    cout << f[n][m] << "\n";
}

int main() {
    freopen("BALANCE.inp", "r", stdin);
    freopen("BALANCE.out", "w", stdout);

    load();
    process();

    return 0;
}
