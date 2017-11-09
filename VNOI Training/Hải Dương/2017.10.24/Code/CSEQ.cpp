#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, h;
int a[N], rmq[22][N];
long long sum[N];

int getmin(int l, int r) {
    int k = log2(r - l + 1);
    return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

int main() {
    freopen("CSEQ.inp", "r", stdin);
    freopen("CSEQ.out", "w", stdout);

    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        rmq[0][i] = i - a[i] + 1;
    }

    int k = log2(n - 1) + 1;
    for (int j = 1; j <= k; ++j) for (int i = 1; i <= n - (1 << j) + 1; ++i) {
        rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        //cerr << i << " " << j << " " << rmq[j][i] << "\n";
    }
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i]; //cerr << getmin(i, i + h - 1) << "\n";
    long long ans = 1e18;
    for (int i = 1; i <= n - h + 1; ++i) if (getmin(i, i + h - 1) >= i) {
        ans = min(ans, 1ll * h * (h + 1) / 2 - (sum[i + h - 1] - sum[i - 1]));
    }
    if (ans == 1e18) puts("-1"); else printf("%lld\n", ans);

    return 0;
}
