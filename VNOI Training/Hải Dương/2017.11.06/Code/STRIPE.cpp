#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

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

vi to_vi(int x) { return vi(1, x); }

ostream& operator << (ostream& cout, const vi &a) {
    printf("%d", a.back());
    for (int i = sz(a) - 2; i >= 0; --i) printf("%08d", a[i]);
    return cout;
}

const int N = 1111;

int n, k;
int a[N];
vi f[N][N];

void load() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) scanf("%d", &a[i]);
}

void process() {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) f[i][j] = to_vi(0);
    for (int i = 0; i < N; ++i) f[i][0] = to_vi(1);
    for (int j = 1; j <= k; ++j) for (int i = 1; i <= n; ++i) {
        f[i][j] = f[i - 1][j];
        if (i > a[j]) f[i][j] = f[i][j] + f[i - a[j] - 1][j - 1];
        else if (i == a[j]) f[i][j] = f[i][j] + f[i - a[j] ][j - 1];
      //  cout << i << " " << j << " " << f[i][j] << "\n";
    }
    cout << f[n][k] << "\n";
}

int main() {
    freopen("STRIPE.inp", "r", stdin);
    freopen("STRIPE.out", "w", stdout);

    load();
    process();

    return 0;
}
