#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long MOD = 12345678910;

int n, tail;
long long st[N];

int main() {
    freopen("PAREN.inp", "r", stdin);
    freopen("PAREN.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        if (!x) st[++tail] = x; else {
            if (!st[tail]) {
                tail--;
                st[++tail] = 1;
            } else {
                long long sum = 0;
                while (tail && st[tail] != 0) sum += st[tail--];
                sum *= 2;
                st[tail] = sum % MOD;
            }
        }
    }
    long long ans = 0;
    while (tail) ans += st[tail--];
    printf("%lld\n", ans % MOD);

    return 0;
}
