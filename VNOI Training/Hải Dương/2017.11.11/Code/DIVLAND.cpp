#include <bits/stdc++.h>
using namespace std;

#define INF 1e15
typedef pair <double, double> ii;
const int N = 5555;

ii operator + (const ii &a, const ii &b) { return ii(a.first + b.first, a.second - b.second); }
ii operator - (const ii &a, const ii &b) { return ii(a.first - b.first, a.second - b.second); }
ii operator * (const double &k, const ii &a) { return ii(k * a.first, k * a.second); }
double operator * (const ii &a, const ii &b) { return a.first * b.second - a.second * b.first;}

int n, m;
double xmin, xmax, diff = INF;
double area = 0;
ii a[N], p[N], c[N];

void load() {
    scanf("%d", &n);
    xmin = 1e9 + 7; xmax = -1e9 - 7;
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        a[i] = ii(x, y);
        xmin = min(xmin, a[i].first);
        xmax = max(xmax, a[i].first);
    }
}

ii intersect(double a1, double b1, double c1, double a2, double b2, double c2) {
    ii u = ii(a1, a2), v = ii(b1, b2), w = ii(c1, c2);
    double D = u * v;
    if (D != 0) return ii(w * v / D, u * w / D);
    if (u * w == 0) return ii(INF, INF); else return ii(-INF, -INF);
}

bool ok(double x) {
    m = 0; bool add = 1;
    for (int i = 0; i < n; ++i) {
        if (add) p[m++] = a[i];
        if (min(a[i].first, a[(i + 1) % n].first) <= x && x <= max(a[i].first, a[(i + 1) % n].first)) {
            add ^= 1;
            p[m++] = intersect(1, 0, x, a[i].second - a[(i + 1) % n].second,
                               a[(i + 1) % n].first - a[i].first,
                               a[i].first * (a[i].second - a[(i + 1) % n].second)
                               + a[i].second * (a[(i + 1) % n].first - a[i].first));
        }
    }
    double area1 = 0;
    for (int i = 0; i < m; ++i) area1 += p[i] * p[(i + 1) % m];
  //  cerr << area1 << " " << area << "\n";

    return area1 + area1 < area;
}

double sqrLen(ii a) { return a.first * a.first + a.second * a.second; }
bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; }

void findConvexHull() {
    sort(a, a + n);
    sort(a + 1, a + n, [&](ii p, ii q) {
         return (p - a[0]) * (q - a[0]) > 0 || (p - a[0]) * (q - a[0]) == 0 && sqrLen(p - a[0]) < sqrLen(q - a[0]);
    });
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && !ccw(c[k - 2], c[k - 1], a[i])) k--;
        c[k++] = a[i];
    }
    for (int i = 0; i < k; ++i) a[i] = c[i];
    n = k;
}

void process() {
    findConvexHull();
    for (int i = 0; i < n; ++i)
        area += a[i] * a[(i + 1) % n];
    double l = xmin, r = xmax, ans = -1;
   // ok(3.4808); ok(3.5580);
    for (int i = 1; i <= 200; ++i) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
            ans = mid;
        } else {
            r = mid;
        }
    }
    printf("%.4f", ans);
}

int main() {
    freopen("DIVLAND.inp", "r", stdin);
    freopen("DIVLAND.out", "w", stdout);

    load();
    process();

    return 0;
}
