#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], w[N], t[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
}

void update(int x, int value) {
    for (; x > 0; x -= x & -x)
        t[x] += value;
}

int get(int x) {
    int res = 0;
    for (; x < N; x += x & -x)
        res += t[x];
    return res;
}

void process() {
    memset(t, 0, sizeof t);
    for (int i = 1; i <= n; ++i) update(i, 1);
    for (int i = n; i > 0; --i) {
        int lo = 1, hi = n + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (get(mid) <= w[i]) hi = mid; else {
                lo = mid;
            }
        }
        a[i] = lo;
        update(lo, -1);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
}

int main() {
    freopen("PORDER.inp", "r", stdin);
    freopen("PORDER.out", "w", stdout);

    int t; scanf("%d", &t);
    while (t--) {
        load();
        process();
    }

    return 0;
}
