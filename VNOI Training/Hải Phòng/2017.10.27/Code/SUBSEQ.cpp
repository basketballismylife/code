#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

class SegmentTree {
private:
    pair <int, int> t[N << 2];
public:
    void update(int k, int l, int r, int i, pair <int, int> value) {
        if (l > i || r < i) return;
        if (l == r) {
            t[k] = value;
            return;
        }
        int mid = (l + r) >> 1;
        update(k << 1, l, mid, i, value);
        update((k << 1) + 1, mid + 1, r, i, value);
        t[k] = max(t[k << 1], t[(k << 1) + 1]);
    }
    pair <int, int> get(int k, int l, int r, int i, int j) {
        if (l > j || r < i) return make_pair(-1e9, 0);
        if (i <= l && r <= j) return t[k];
        int mid = (l + r) >> 1;
        pair <int, int> x = get(k << 1, l, mid, i, j);
        pair <int, int> y = get((k << 1) + 1, mid + 1, r, i, j);
        return max(x, y);
    }
} it;

int n, delta;
int a[N], pre[N], dp[N];
vector <int> c;

int main() {
    freopen("SUBSEQ.inp", "r", stdin);
    freopen("SUBSEQ.out", "w", stdout);

    scanf("%d%d", &n, &delta);
    for (int i = 1; i <= n;++i) {
        scanf("%d", &a[i]);
        a[i + n] = a[i] - delta;
        a[i + 2 * n] = a[i] + delta;
        c.push_back(a[i]);
        c.push_back(a[i + n]);
        c.push_back(a[i + 2 * n]);
    }

    sort(c.begin(), c.end());
    for (int i = 1; i <= 3 * n; ++i)
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
    int ans = 0, id = 0;
    for (int i = 1; i <= n; ++i) {
        pair <int, int> w = it.get(1, 1, 3 * n, a[i + n], a[i + 2 * n]);
        dp[i] = w.first + 1;
        pre[i] = w.second;
        it.update(1, 1, 3 * n, a[i], {dp[i], i});
        if (dp[i] > ans) {
            ans = dp[i];
            id = i;
        }
        //cerr << i << " " << w.first << " " << w.second << "\n";
    }

    printf("%d\n", ans);
    vector <int> res;
    do {
        res.push_back(c[a[id] - 1]);
        id = pre[id];
    } while (id);
    reverse(res.begin(), res.end());
    for (int v : res) printf("%d ", v);

    return 0;
}
