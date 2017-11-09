#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N];
vector <int> s[2];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
}

bool cmp1(int x, int y) { return a[x] < a[y]; }
bool cmp2(int x, int y) { return b[x] > b[y]; }

bool ok(long long x) {
    for (int v : s[0]) {
        x -= a[v];
        if (x < 0) return 0;
        x += b[v];
    }
    for (int v : s[1]) {
        x -= a[v];
        if (x < 0) return 0;
        x += b[v];
    }
    return 1;
}

void process() {
    for (int i = 1; i <= n; ++i) if (a[i] <= b[i])
        s[0].push_back(i);
    else
        s[1].push_back(i);
    sort(s[0].begin(), s[0].end(), cmp1);
    sort(s[1].begin(), s[1].end(), cmp2);

    long long l = 1, r = 1e18, ans = -1;
    //cerr << ok(9) << "\n";
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    for (int v : s[0]) printf("%d ", v);
    for (int v : s[1]) printf("%d ", v);
}

int main() {
    freopen("PRJCHAIN.inp", "r", stdin);
    freopen("PRJCHAIN.out", "w", stdout);

    load();
    process();

    return 0;
}
