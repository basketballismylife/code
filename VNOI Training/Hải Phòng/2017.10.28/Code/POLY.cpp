#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> ii;

const int N = 222;

int n, k, K;
ii A[N], p[N];
long long dp[N][N][N];

void load() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &A[i].first, &A[i].second);
}

ii operator - (ii a, ii b) { return ii(b.first - a.first, b.second - a.second); }
long long operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }

long long sqrLen(ii a) { return a.first * a.first + a.second * a.second; }
bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; }
long long area(ii a, ii b, ii c) { return abs((b - a) * (c - a)); }

void findConvexHull() {
    sort(A, A + n);
    sort(A + 1, A + n, [&](ii p, ii q) {
         return (p - A[0]) * (q - A[0]) > 0 || (p - A[0]) * (q - A[0]) == 0 && sqrLen(p - A[0]) < sqrLen(q - A[0]);
    });
    k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
}

void process() {
    findConvexHull();

    for (int z = 3; z <= K; ++z) {
        for (int x = 0; x < k; ++x) for (int y = x + 1; y < k; ++y) for (int o = y + 1; o < k; ++o)
            dp[z][x][o] = max(dp[z][x][o], dp[z - 1][x][y] + area(p[x], p[y], p[o]));
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j)
        ans = max(ans, dp[K][i][j]);
    printf("%.2f", (double) ans * 0.5);
}

int main() {
    freopen("POLY.inp", "r", stdin);
    freopen("POLY.out", "w", stdout);

    load();
    process();

    return 0;
}
