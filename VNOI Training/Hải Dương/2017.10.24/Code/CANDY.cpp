#include <bits/stdc++.h>
using namespace std;

const int N = 501, V = 1e5 + 10;

int n, sum;
int a[N], dp[N][V];

int main() {
    freopen("CANDY.inp", "r", stdin);
    freopen("CANDY.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for (int i = 1; i <= sum; ++i) dp[0][i] = -1e9;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= sum; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
        if (j + a[i] <= sum) dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]] + a[i]);
    }

    cerr << dp[n][0] << "\n";
    int ans = (dp[n][0] != -1e9) ? dp[n][0] / 2 + (sum - dp[n][0]) : sum;
    printf("%d\n", ans);

    return 0;
}
