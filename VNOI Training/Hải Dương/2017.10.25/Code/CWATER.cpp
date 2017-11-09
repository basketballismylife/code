#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void euclid_gcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a; x = 1; y = 0;
        return;
    }
    int x1, y1;
    euclid_gcd(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    freopen("CWATER.inp", "r", stdin);
    freopen("CWATER.out", "w", stdout);

    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);

        int d, x, y;
        if (a < b) swap(a, b);
        euclid_gcd(a, b, d, x, y);

        long long ans = -1;
        if (c % d == 0) {
            int a1 = a / d, b1 = b / d, c1 = c / d;
            long long x1 = 1ll * x * c1, y1 = 1ll * y * c1;
            y1 = (y1 % a1 + a1) % a1;
            x1 = (c - b * y1) / a;
            ans = min(abs(x1) + abs(y1), abs(x1 + b1) + abs(y1 - a1));
        }
        printf("%lld\n", ans);
    }

    return 0;
}
