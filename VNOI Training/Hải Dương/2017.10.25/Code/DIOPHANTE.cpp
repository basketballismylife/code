#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void euclid_gcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a; x = 1; y = 0; return;
    }
    int x1, y1;
    euclid_gcd(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    freopen("DIOPHANTE.inp", "r", stdin);
    freopen("DIOPHANTE.out", "w", stdout);

    scanf("%d%d%d", &a, &b, &c);

    int x, y, d;
    euclid_gcd(a, b, d, x, y); //cerr << x << " " << y << "\n";
    long long ans = 0;
    if (c % d == 0) {
        int a1 = a / d, b1 = b / d, c1 = c / d;
        //while (!x) {x += b1; y -= a1; }
        //while (!y) x += b1; y -= a1;}
        long long l = -1ll * c1 * x / b1, r = 1ll * c1 * y / a1;
        ans = r - l - 1;
        if (1ll * c1 * x + b1 * l > 0 && 1ll * c1 *y - a1 * l > 0) ans++;
        if (1ll * c1 * x + b1 * r > 0 && 1ll * c1 *y - a1 * r > 0) ans++;
    }
    printf("%lld\n", ans);

    return 0;
}
