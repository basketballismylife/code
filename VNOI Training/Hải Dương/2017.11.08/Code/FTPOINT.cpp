#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8
typedef pair <double, double> ii;
const int N = 1111;

ii operator + (const ii &a, const ii &b) { return ii(a.first + b.first, a.second + b.second); }
ii operator - (const ii &a, const ii &b) { return ii(a.first - b.first, a.second - b.second); }
ii operator * (const double k, const ii &b) { return ii(k * b.first, k * b.second); }
double operator * (const ii &a, const ii &b) { return a.first * b.second - a.second * b.first; }
double operator ^ (const ii &a, const ii &b) { return a.first * b.first + a.second * b.second; }

double sqrLen(ii a) { return a.first * a.first + a.second * a.second; }
bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; } // counter clockwise
bool cw(ii a, ii b, ii c) { return (b - a) * (c - b) < 0; } // clockwise

int n;
double xmin = 1e9 + 7, xmax, ymax, ymin = 1e9 + 7;
ii a[N];

void load() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        xmin = min(xmin, a[i].first);
        xmax = max(xmax, a[i].first);
        ymin = min(ymin, a[i].second);
        ymax = max(ymax, a[i].second);
    }
}

double calc1(ii x) {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += sqrt(sqrLen(a[i] - x));
    }
    return ans;
}

double calc(double x) {
    double l = ymin, r = ymax;
    for (int i = 0; i < 200; ++i) {
        double y1 = (2 * l + r) / 3;
        double y2 = (l + 2 * r) / 3;
        if (calc1(ii(x, y1)) < calc1(ii(x, y2))) {
            r = y2;
        } else {
            l = y1;
        }
    }
    return calc1(ii(x, l));
}

void process() {
    double l = xmin, r = xmax, ans = 1e18;
    for (int i = 0; i < 200; ++i) {
        double x1 = (2 * l + r) / 3;
        double x2 = (l + 2 * r) / 3;
        double v1 = calc(x1); double v2 = calc(x2);
        ans = min({ans, v1, v2});
        if (v1 < v2) {
            r = x2;
        } else {
            l = x1;
        }
    }
    cout << fixed << setprecision(3);
    cout << ans << "\n";
}

int main() {
    freopen("FTPOINT.inp", "r", stdin);
    freopen("FTPOINT.out", "w", stdout);

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    load();
    process();

    return 0;
}
