#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];
vector < pair <int, int> > c;

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", b + i);
    }
}

bool ok(int x) {
    c.clear();
    for (int i = 1, j = 1; i <= n; ++i) {
        if (a[i] >= x) continue;
        while (a[i] + b[j] < x && j <= m) j++;
        if (j <= m) c.push_back({i, j});
        else return 0;
        j++;
    }
    return 1;
}

void process() {
    vector < pair <int, int> > res;
    int l = 0, r = 1e9 + 7, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
            res = c;
        } else {
            r = mid - 1;
        }
    }
    printf("%d %d\n", ans, (int) res.size());
    for (int i = 0; i < res.size(); ++i) printf("%d %d\n", res[i].first, res[i].second);
}

int main() {
    freopen("WALL.inp", "r", stdin);
    freopen("WALL.out", "w", stdout);

    load();
    process();

    return 0;
}
