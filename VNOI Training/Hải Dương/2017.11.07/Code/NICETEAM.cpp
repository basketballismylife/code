#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
long long k;
long long a[N], b[N], s[N], f[N];

void load() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        s[i] = s[i - 1] + a[i];
    }
}

bool ok(long long x) {
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + a[i] - x;
        f[i] = min(f[i - 1], b[i]);
    }
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j < i && s[i] - s[j + 1] >= k) j++;
        if (b[i] >= f[j]) return 1;
    }
    return 0;
}

void process() {
    long long lo = 0, hi = s[n] + 1, ans = 0;
   // cerr << ok(15) << "\n";
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if (ok(mid)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("NICETEAM.inp", "r", stdin);
    freopen("NICETEAM.out", "w", stdout);

    load();
    process();

    return 0;
}
