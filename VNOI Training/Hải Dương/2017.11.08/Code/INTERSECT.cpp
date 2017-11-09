#include <bits/stdc++.h>
using namespace std;

typedef pair <double, double> ii;

ii operator + (const ii &a, const ii &b) { return ii(a.first + b.first, a.second + b.second); }
ii operator - (const ii &a, const ii &b) { return ii(a.first - b.first, a.second - b.second); }
ii operator * (const double k, const ii &b) { return ii(k * b.first, k * b.second); }
double operator * (const ii &a, const ii &b) { return a.first * b.second - a.second * b.first; }
double operator ^ (const ii &a, const ii &b) { return a.first * b.first + a.second * b.second; }

double sqrLen(ii a) { return a.first * a.first + a.second * a.second; }
bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; } // counter clockwise
bool cw(ii a, ii b, ii c) { return (b - a) * (c - b) < 0; } // clockwise

ii a[4];

bool colinear(ii a, ii b, ii c) {
    if ((b - a) * (c - b) != 0) return 0;
    if (a > b) swap(a, b); if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return a.first <= b.first && b.first <= c.first && a.second <= b.second && b.second <= c.second;
}

bool intersect(ii a, ii b, ii c, ii d) {
    if (ccw(c, a, d) != ccw(c, b, d) && ccw(a, c, b) != ccw(a, d, b)) return 1;
    if (colinear(a, b, c) || colinear(a, b, d) || colinear(c, d, a) || colinear(c, d, b)) return 1;
    return 0;
}

int main() {
    freopen("INTERSECT.inp", "r", stdin);
    freopen("INTERSECT.out", "w", stdout);

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    #define A a[0]
    #define B a[1]
    #define C a[2]
    #define D a[3]
    while (t--) {
        for (int i = 0; i < 4; ++i) cin >> a[i].first >> a[i].second;

        ii ab = B - A, ac = C - A, dc = C - D;
        double t = ab * dc;
        if (t != 0) {
            double p = ab * ac / t, q = ac * dc / t;
            if (0 <= p && p <= 1 && 0 <= q && q <= 1) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            if (ac * dc != 0 || ab * ac != 0) {
                puts("NO");
            } else if (ac * dc == 0 && ac * ac == 0) {
                if (((A - C)^(B - C)) <= 0
                    || ((A - D) ^ (B - D)) <= 0
                    || ((C - A) ^ (D - A)) <= 0
                    || ((C - B) ^ (D - B)) <= 0) puts("YES");
                else puts("NO");
            }
        }
        if (intersect(A, B, C, D)) puts("YES"); else puts("NO");
    }

    return 0;
}
