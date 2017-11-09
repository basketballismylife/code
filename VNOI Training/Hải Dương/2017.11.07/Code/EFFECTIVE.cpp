#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

class SegmentTree {
private:
    int t[N << 2];
public:
    #define mid ((l + r) >> 1)
    void init() {
        for (int i = 0; i < N << 2; ++i) t[i] = 1e9 + 7;
    }
    void update(int k, int l, int r, int i, int value) {
        if (l > i || r < i) return;
        if (l == r) {
            t[k] = value;
            return;
        }
        update(k << 1, l, mid, i, value);
        update((k << 1) + 1, mid + 1, r, i, value);
        t[k] = min(t[k << 1], t[(k << 1) + 1]);
    }
    int get(int k, int l, int r, int i, int j) {
        if (l > j || r < i) return 1e9 + 7;
        if (i <= l && r <= j) return t[k];
        int x = get(k << 1, l, mid, i, j);
        int y = get((k << 1) + 1, mid + 1, r, i, j);
        return min(x, y);
    }
} it;

int n, m;
long long a[N], f[N];
vector <long long> c;

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1]; a[i + n] = a[i] - m;
        c.push_back(a[i]); c.push_back(a[i + n]);
    }
    c.push_back(0);
    sort(c.begin(), c.end());
}

void process() {
    it.init();
    for (int i = 0; i <= n << 1; ++i) a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
    it.update(1, 1, 2 * n + 1, a[0], 0); //cerr << a[0] << "\n";
    for (int i = 1; i <= n; ++i) {
        int w = it.get(1, 1, 2 * n + 1, a[i + n], a[i]);
        f[i] = w + 1;
        it.update(1, 1, 2 * n + 1, a[i], f[i]);
    }
    if (f[n] < 1e6)
        printf("%d\n", f[n]);
    else puts("0");
}

int main() {
    freopen("EFFECTIVE.inp", "r", stdin);
    freopen("EFFECTIVE.out", "w", stdout);

    load();
    process();

    return 0;
}
