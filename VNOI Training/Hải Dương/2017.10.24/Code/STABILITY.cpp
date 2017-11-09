#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e5 + 10;

int n;
pair <int, int> a[N];
int v[222], sum[N];

int main() {
    freopen("STABILITY.inp", "r", stdin);
    freopen("STABILITY.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i].second);

    sort(a + 1, a + n + 1);
    for (int i = n; i > 0; --i) sum[i] = sum[i + 1] + a[i].second;

    int num = 0, ans = 1e9 + 7;
    for (int i = 1; i <= n; ) {
        int j = i; while (a[i].first == a[j].first && j <= n) j++;
        int cnt = j - i; num += cnt;
        if (2 * cnt > num) {
            ans = min(ans, sum[j]);
        } else {
            int need = num - 2 * cnt + 1, cur = 0;
            for (int j = 1; j <= 200; ++j) if (v[j]) {
                cur += min(v[j], need) * j;
                need -= min(need, v[j]);
            }
            ans = min(ans, cur + sum[j]);
        }
        while (i < j) v[a[i++].second]++;
    }

    printf("%d\n", ans);

    return 0;
}
