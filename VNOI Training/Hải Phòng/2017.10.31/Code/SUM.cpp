#include <bits/stdc++.h>
using namespace std;

const int N = 123457;

int n, mod;
long long sum[N];
char s[N];

void load() {
    scanf("%d%d", &n, &mod);
    scanf("%s", s + 1);
}

void process() {
    sum[0] = 1;
    long long pw = 1;
    for (int i = 1; i <= n; ++i) {
        pw = pw * 10 % mod;
        sum[i] = (sum[i - 1] + pw) % mod;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (s[i] - '0') * sum[n - i] * i % mod) % mod;
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("SUM.inp", "r", stdin);
    freopen("SUM.out", "w", stdout);

    load();
    process();

    return 0;
}
