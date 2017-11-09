#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int MOD = 1e8;

typedef vector <long long> vi;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < sz(a) - 1; ++i) {
        a[i + 1] +=a[i] / MOD; a[i] %= MOD;
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

vi operator * (const vi &a, const vi &b) {
    vi c(sz(a) + sz(b), 0);
    for (int i = 0; i < sz(a); ++i) for (int j = 0; j < sz(b); ++j)
        c[i + j] += a[i] * b[j];
    return fix(c), c;
}

vi to_vi(int x) { return vi(1, x); }

bool operator > (const vi &a, const vi &b) {
    if (sz(a) != sz(b)) return sz(a) > sz(b);
    for (int i = sz(a) - 1; i >= 0; --i) if (a[i] != b[i])
        return a[i] > b[i];
    return 0;
}
/*
istream& operator >> (istream& cin, vi &a) {
    string s; cin >> s;
    a.resize(sz(a) / 8 + 1);
    for (int i = 0; i < sz(s); ++i) {
        int x = (sz(s) - i - 1) / 8;
        a[x] = a[x] * 10 + s[i] - '0';
    }
    return fix(a), cin;
}
*/
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
    printf("%lld", a.back());
    for (int i = sz(a) - 2; i >= 0; --i) printf("%08lld", a[i]);
    return cout;
}

const int N = 55;

int n;
bool cnt[N];
vi f[N];

void load() {
    scanf("%d", &n);
    f[0] = f[1] = to_vi(1);
    for (int i = 2; i <= n; ++i) f[i] = f[i - 1] * to_vi(i);
    cout << f[n] << "\n";
}

int get(int x) {
    int res = 0;
    for (int i = 1; i < x; ++i) res += !cnt[i];
    cnt[x] = 1;
    return res;
}

void process() {
    int t;
    while (~scanf("%d", &t)) {
        if (t == 1) {
            memset(cnt, 0, sizeof cnt);
            vi ans = to_vi(1);
            for (int i = 1; i <= n; ++i) {
                int x; scanf("%d", &x);
                int w = get(x); //cerr << w << "\n";
                ans = ans + to_vi(w) * f[n - i];
            }
            cout << ans << "\n";
        } else {
            memset(cnt, 0, sizeof cnt);
            vi p; cin >> p;
            for (int i = 1; i <= n; ++i) {
                int j;
                for (j = 1; j <= n; ++j) if (!cnt[j]) {
                    if (p > f[n - i]) {
                        p = p - f[n - i];
                    }else break;
                }
                printf("%d ", j); cnt[j] = 1;
            }
            puts("");
        }
    }
}

int main() {
    freopen("HV.inp", "r", stdin);
    freopen("HV.out", "w", stdout);

    load();
    process();

    return 0;
}
