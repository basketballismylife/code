#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, MOD = 1e9 + 7;

int n, k;
long long f[N], pw[N];

int main() {
    freopen("TOSS.inp", "r", stdin);
    freopen("TOSS.out", "w", stdout);

    scanf("%d%d", &n, &k);

    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % MOD;
    for (int i = 1; i <= n; ++i) {
        if (i >= k) {
            if (i - k - 1 < 0)
                f[i] = (2 * f[i - 1] + 1) % MOD;
            else {
                f[i] = (2 * f[i - 1] + pw[i - k - 1] - f[i - k - 1]) % MOD;
                f[i] = (f[i] + MOD) % MOD;
            }
        }
    }
    printf("%lld\n", f[n]);

    return 0;
}
