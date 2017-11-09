#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair <ll, ll> ii;

const int N = 1e5 + 10;

int n, k;
ii A[N], p[N];

ii operator + (ii a, ii b) { return ii(a.first + b.first, a.second + b.second); }
ii operator - (ii a, ii b) { return ii(b.first - a.first, b.second - a.second); }
long long operator % (ii a, ii b) { return a.first * b.first + a.second * b.second; }
long long operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }

bool ccw(ii a, ii b, ii c) { // counter clockwise
    return (b - a) * (c - b) > 0;
}

long long sqrLen(ii a) { return a.first * a.first + a.second * a.second; }

int main() {
    freopen("CONVEXHULL.inp", "r", stdin);
    freopen("CONVEXHULL.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &A[i].first, &A[i].second);

    sort(A, A + n, [&](ii p, ii q) { return p.second < q.second || p.second == q.second && p.first < q.first; });
    //sort(A + 1, A + n, [&](ii p, ii q) { return (p - A[0]) * (q - A[0]) > 0 || (p - A[0]) * (q - A[0]) == 0 && sqrLen(p - A[0]) < sqrLen(q - A[0]); });
    k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
    for (int i = n - 1, t = k + 1; i >= 0; --i) {
        while (k >= t && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
    if (p[0] == p[k - 1]) k--;

    long long area = 0;
    for (int i = 0; i < k; ++i)
        area += p[i] * p[(i + 1) % k];
    printf("%d\n%lld", k, area / 2);
    if (area & 1) puts(".5"); else puts(".0");
    for (int i = 0; i < k; ++i) printf("%lld %lld\n", p[i].first, p[i].second);

    return 0;
}
