#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> ii;

const int N = 1e5 + 10;

int n, m, k;
ii A[N], p[N];
long long t[N];

ii operator - (ii a, ii b) { return  make_pair(b.first - a.first, b.second - a.second); }
long long operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }

bool cw(ii a, ii b, ii c) { return (b - a) * (c - b) < 0; }

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        t[i] += t[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        A[i] = make_pair(t[i - 1], t[i]);
}

void findConvexLine() {
    k = 0;
    p[k++] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) {
        while (k > 1 && !cw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    }
}

long long get(int x, int y) {
    //ii v = make_pair(x, y);
    int l = 0, r = k - 2, cur = 0;
    while (l <= r) { // (l - 1) * v <= 0 && (r + 1) * v > 0
        int mid = (l + r) >> 1;
        if ((p[mid + 1].first - p[mid].first) * y <= (p[mid + 1].second - p[mid].second) * x) {
            l = mid + 1;
            cur = l;
        } else {
            r = mid - 1;
        }
    }
    return make_pair(x, y) * p[cur];
}

void process() {
    findConvexLine();
    int x = 0, y = 0;
    long long delay = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &y);
        delay += get(x, y);
      //  cerr << get(x, y) << "\n";
        x = y;
    }
    long long ans = delay + 1ll * t[n] * x;
    printf("%lld\n", ans);
}

int main() {
    freopen("READERS.inp", "r", stdin);
    freopen("READERS.out", "w", stdout);

    load();
    process();

    return 0;
}
