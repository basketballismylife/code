#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

ull a, MOD, k;

ull mul(ll a, ll b) {
    ll q = trunc((long double) a * b / MOD);
    ll r = a * b - q * MOD;
    return (r + MOD) % MOD;
}

ull power(ull n, ull k) {
    ull e = 1;
    while (k) {
        if (k & 1) e = mul(e, n);
        n = mul(n, n); k >>= 1;
    }
    return e;
}

int main() {
    freopen("DIGIT.inp", "r", stdin);
    freopen("DIGIT.out", "w", stdout);

    scanf("%llu%llu%llu", &a, &MOD, &k);

    ull ans = mul(a % MOD, power(10, k - 1));
    ans = ans * 10 / MOD;
    printf("%llu\n", ans);

    return 0;
}
