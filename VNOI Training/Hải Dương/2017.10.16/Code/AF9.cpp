#include <bits/stdc++.h>
using namespace std;

const int N = 1111;

int n, m, head, tail, ans;
int h[N], l[N], r[N], st[N];

int main() {
    freopen("AF9.inp", "r", stdin);
    freopen("AF9.out", "w", stdout);

    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; scanf("%d", &x);
            h[j] = x ? h[j] + 1 : 0;
        }
        head = 0; tail = -1;
        for (int j = 1; j <= n; ++j) {
            l[j] = 0; r[j] = n + 1;
            while (head <= tail && h[st[tail]] >= h[j]) {
                r[st[tail--]] = j;
            }
            if (head <= tail) l[j] = st[tail];
            st[++tail] = j;
        }
        for (int j = 1; j <= n; ++j)
            ans = max(ans, h[j] * (r[j] - l[j] - 1));
    }
    printf("%d\n", ans);

    return 0;;
}
