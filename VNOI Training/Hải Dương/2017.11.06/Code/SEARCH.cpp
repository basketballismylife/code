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
    for (int i = 0; i < sz(b); ++i) c[i] += b[i];
    fix(c);
    return c;
}

ostream& operator << (ostream& cout, const vi &a) {
    printf("%d", a.back());
    for (int i = sz(a) - 2; i >= 0; --i) printf("%08d", a[i]);
    return cout;
}

vi to_vi(int x) { return vi(1, x); }

const int N = 222;

int n, m;
vi c[N][N];

void load() {
    scanf("%d%d", &n, &m);
}

void process() {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) c[i][j] = to_vi(0);
    c[0][0] = to_vi(1);
    for (int i = 1; i < N; ++i) for (int j = 1; j < N; ++j)
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    vi ans = to_vi(0);
    for (int i = n; i < m; ++i) if ((i - n) % 2 == 0) {
        ans = ans + c[i][n];
    }
    cout << ans << "\n";
}

int main() {
    freopen("SEARCH.inp", "r", stdin);
    freopen("SEARCH.out", "w", stdout);

    load();
    process();

    return 0;
}
