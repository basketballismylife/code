#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
long long k;
long long a[N];

int main() {
    freopen("COINCOL.inp", "r", stdin);
    freopen("COINCOL.out", "w", stdout);

    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);

    sort(a + 1, a + n + 1);
    long long sum = 0; int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int id = upper_bound(a + 1, a + n + 1, sum + a[i]) - a - 1;
        if (sum < a[i] && sum + a[i] <= k && id <= i) {
            sum += a[i];
            cnt++;
        }
    }
    printf("%d %lld\n", cnt, sum);

    return 0;
}
