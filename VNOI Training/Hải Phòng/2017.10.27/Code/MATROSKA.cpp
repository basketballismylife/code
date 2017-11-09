#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

class SegmentTree {
private:
    int t[N << 2], lz[N << 2];
public:
    void lazy(int k, int l, int r) {
        if (!lz[k]) return;
        if (l != r) {
            lz[k << 1] += lz[k];
            lz[(k << 1) + 1] += lz[k];
            t[k << 1] += lz[k];
            t[(k << 1) + 1] += lz[k];
        }
        lz[k] = 0;
    }
    void update(int k, int l, int r, int i, int j, int value) {
        if (l > j || r < i) return;
        lazy(k, l, r);
        if (i <= l && r <= j) {
            lz[k] += value;
            t[k] += value;
            return;
        }
        int mid = (l + r) >> 1;
        update(k << 1, l, mid, i, j, value);
        update((k << 1) + 1, mid + 1, r, i, j, value);
        t[k] = min(t[k << 1], t[(k << 1) + 1]);
    }
    int get() { return t[1]; }
} it;

int n;
int a[N], b[N];

int main() {
    freopen("MATROSKA.inp", "r", stdin);
    freopen("MATROSKA.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
     //   cerr << a[i] << "\n";
    }

    int ans = 0;
    it.update(1, 1, n, 1, a[1], -1);
    it.update(1, 1, n, 1, a[2] - 1, 1);
    if (it.get() >= 0) {
        ans = 1;
    }
    for (int k = 2; 2 * k <= n; ++k) {
        it.update(1, 1, n, 1, a[k], -1);
        it.update(1, 1, n,1 , a[k] - 1, -1);
        it.update(1, 1, n, 1, a[2 * k - 1] - 1, 1);
        it.update(1, 1, n, 1, a[2 * k] - 1, 1);
        if (it.get() >= 0) {
            ans = k;
        }
        //cerr << it.get() << "\n";
    }
    printf("%d\n", ans);

    return 0;
}
