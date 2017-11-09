#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, d, head[2], tail[2];
int st[2][N], mn[N], mx[N];

void load() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i <= 1e6; ++i) mn[i] = 1e6 + 1, mx[i] = -1;
    for (int i = 1; i <= n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        mn[x] = min(mn[x], y); mx[x] = max(mx[x], y);
    }
}

bool ok(int x) {
    head[0] = head[1] = 0; tail[0] = tail[1] = -1;
    for (int i = 0; i <= 1e6; ++i) if (mx[i] != -1) {
        while (head[0] <= tail[0] && i - st[0][head[0]] > x) head[0]++;
        while (head[1] <= tail[1] && i - st[1][head[1]] > x) head[1]++;

        while (head[0] <= tail[0] && mn[st[0][tail[0]]] > mn[i]) tail[0]--;
        while (head[1] <= tail[1] && mx[st[1][tail[1]]] < mx[i]) tail[1]--;

        st[0][++tail[0]] = i; st[1][++tail[1]] = i;
        if (mx[st[1][head[1]]] - mn[st[0][head[0]]] >= d) {
            return 1;
        }
    }
    return 0;
}

void process() {
    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("FPOT.inp", "r", stdin);
    freopen("FPOT.out", "w", stdout);

    load();
    process();

    return 0;
}
