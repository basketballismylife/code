#include <bits/stdc++.h>
using namespace std;

const int N = 44;

int n, m;
long long s;
long long a[N], st[1 << 20];

int main() {
    freopen("SUMS.inp", "r", stdin);
    freopen("SUMS.out", "w", stdout);

    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%lld", a + i);

    int k = n / 2;
    for (int x = 0; x < 1 << k; ++x) {
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += (x >> i & 1) * a[i];
            if (sum > s) break;
        }
        if (sum <= s) st[m++] = sum;
    }
    sort(st, st + m);
    long long ans = 0;
    for (int x = 0; x < 1 << (n - k); ++x) {
        long long sum = 0;
        for (int i = 0; i < n - k; ++i) {
            sum += (x >> i & 1) * a[i + k];
            if (sum > s) break;
        }
        if (sum <= s) ans += upper_bound(st, st + m, s - sum) - lower_bound(st, st + m, s - sum);
    }
    printf("%lld\n", ans);

    return 0;
}
