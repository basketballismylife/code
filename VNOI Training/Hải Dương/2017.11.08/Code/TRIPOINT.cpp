#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int N = 2222;

ii operator - (ii a, ii b) {
    int x = b.first - a.first;
    int y = b.second - a.second;
    if (y < 0) x = -x, y = -y;
    return make_pair(x / __gcd(x, y), y / __gcd(x, y));
}
int sqrLen(ii a) { return a.first * a.first + a.second * a.second; }

int n;
ii a[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
}

void process() {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        map < pair <int, int>, int> f;
        for (int j = i + 1; j <= n; ++j) {
            f[a[i] - a[j]]++;
        }
        for (auto it : f) {
      //      cerr << it.first.first << " " << it.first.second << " " << it.second << "\n";
            ans += 1ll * it.second * (it.second - 1) / 2;
        }
        //cerr << "\n";
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("TRIPOINT.inp", "r", stdin);
    freopen("TRIPOINT.out", "w", stdout);

    load();
    process();

    return 0;
}
