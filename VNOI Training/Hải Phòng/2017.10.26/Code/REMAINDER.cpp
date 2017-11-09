#include <bits/stdc++.h>
using namespace std;

template <class T> void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') nega = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> wri(T x) { if (x / 10) wri(x / 10); putchar(x % 10 + '0'); }
template <class T> write(T x) { if (x < 0) putchar('-'); wri(abs(x)); }
template <class T> writeln(T x) { write(x); putchar('\n'); }

#define ll long long
#define ull unsigned long long

ull A, B, MOD;

ull mul(ull a, ull b) {
    ull q = trunc((long double) a * b / MOD);
    ll r = (ll) ((ll)a * b - (ll)q * MOD) % (ll)MOD;
    return (r + MOD) % MOD;
}

ull calc(ull n, ull k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    if (k % 2 != 0) return (1 + mul(n, calc(n, k - 1))) % MOD;
    ull t = calc(n, k / 2);
    return mul(t, mul(t, n - 1) + 2);
}

int main() {
    freopen("REMAINDER.inp", "r", stdin);
    freopen("REMAINDER.out", "w", stdout);

    int t; read(t);
    while (t--) {
        read(A); read(B); read(MOD);
        ull H = 1; while (H <= A) H *= 10;
        printf("%llu\n", mul(A, calc(H, B)));
    }

    return 0;
}
