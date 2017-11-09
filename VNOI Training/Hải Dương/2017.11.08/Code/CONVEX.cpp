#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair <ll, ll> ii;
const int N = 2e5 + 10;

ii operator - (ii a, ii b) { return make_pair(b.first - a.first, b.second - a.second); }
ll operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }
ll sqrLen(ii a) { return a.first * a.first + a.second * a.second; }

bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; }

int n, m;
ii A[N], p[N];

void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &A[i].first, &A[i].second);
}

void findConvexHull() {
    sort(A, A + n);
    sort(A + 1, A + n, [&] (ii p, ii q) {
         return (p - A[0]) * (q - A[0]) > 0 || (p - A[0]) * (q - A[0]) == 0 && sqrLen(p - A[0]) < sqrLen(q - A[0]);
    });
    m = 0;
    for (int i = 0; i < n; ++i) {
        while (m > 1 && !ccw(p[m - 2], p[m - 1], A[i])) m--;
        p[m++] = A[i];
    }
}

void process() {
    findConvexHull();
    double per = 0; long long area = 0;
    for (int i = 0; i < m; ++i) {
        area += p[i] * p[(i + 1) % m];
        per += sqrt(sqrLen(p[i] - p[(i + 1) % m]));
    }
    printf("%d\n%.2f\n%lld", m, per, area / 2);
    if (area & 1) puts(".5"); else puts(".0");
}

int main() {
    freopen("CONVEX.inp", "r", stdin);
    freopen("CONVEX.out", "w", stdout);

    load();
    process();

    return 0;
}
