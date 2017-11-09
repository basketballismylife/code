#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> ii;

const int N = 3333;

int n, k;
ii A[N], p[N];

ii operator - (ii a, ii b) { return ii(b.first - a.first, b.second - a.second); }
long long operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }
bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; }

long long area(ii a, ii b, ii c) { return abs((b - a) * (c - a)); }
long long sqrLen(ii a) { return a.first * a.first + a.second * a.second; }

void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &A[i].first, &A[i].second);
}

void findConvexHull() { /* way 1
    sort(A, A + n);
    for (int i = 0; i < n; ++i) {
        while (k > 1 && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
    if (p[0] == p[k - 1]) k--;*/
    // way 2
    sort(A, A + n, [&](ii p, ii q) { return p.second < q.second || p.second == q.second && p.first < q.first; });
    sort(A + 1, A + n, [&](ii p, ii q) { return (p - A[0]) * (q - A[0]) > 0 || (p - A[0]) * (q - A[0]) == 0 && sqrLen(p - A[0]) < sqrLen(q - A[0]); });
    k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
}

void process() {
    findConvexHull();
    long long ans = 0;
    for (int x = 0, y = 1, z = 2; x < k; ++x) {
        //cerr << p[x].first << " " << p[y].second << "\n";
        if (x == y) y = (y + 1) % k;
        if (y == z) z = (z + 1) % k;
        while (1) {
            while (area(p[x], p[y], p[z]) <= area(p[x], p[y], p[(z + 1) % k])) z = (z + 1) % k;
            if (area(p[x], p[y], p[z]) <= area(p[x], p[(y + 1) % k], p[z])) {
                y = (y + 1)% k;
                continue;
            } else break;
        }
        ans = max(ans, area(p[x], p[y], p[z]));
    }
    printf("%lld.%c\n", ans / 2, (ans & 1) ? '5' : '0');
}

int main() {
    freopen("TRILAND.inp", "r", stdin);
    freopen("TRILAND.out", "w", stdout);

    load();
    process();

    return 0;
}
