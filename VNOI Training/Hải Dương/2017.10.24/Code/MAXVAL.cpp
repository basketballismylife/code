#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];

int get(int x) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    freopen("MAXVAL.inp", "r", stdin);
    freopen("MAXVAL.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = n - 1; i > 0; --i) if (a[i] < a[i + 1]) {
        if (a[i] < ans) break;
        for (int j = 2; (j - 1) * a[i] <= a[n]; ++j) {
            int id = get(j * a[i]);
            ans = max(ans, a[id] % a[i]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
