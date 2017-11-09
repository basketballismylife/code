#include <bits/stdc++.h>
using namespace std;

template <class T> T getBit(T x, T k) { return x >> k & 1; }
template <class T> T offBit(T x, T k) { return x ^ (1 << k); }
const int N = 20;

int n, H;
int h[N], w[N], s[N];
int f[1 << N], g[1 << N], t[1 << N];

void load() {
    scanf("%d%d", &n, &H);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", h + i, w + i, s + i);
}

void process() {
    f[0] = 1e9 + 7;
    int ans = -1;
    for (int x = 1; x < 1 << n; ++x) for (int i = 0; i < n; ++i) if (getBit(x, i) && s[i] >= g[offBit(x, i)]) {
        if (f[x] < min(f[offBit(x, i)], s[i] - g[offBit(x, i)])) {
            f[x] = min(f[offBit(x, i)], s[i] - g[offBit(x, i)]);
            g[x] = g[offBit(x, i)] + w[i];
            t[x] = t[offBit(x, i)] + h[i];
        }
        if (t[x] >= H) {
            ans = max(ans, f[x]);
        }
    }
    if (ans == -1) puts("Mark is too tall");
    else printf("%d\n", ans);
}

int main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    load();
    process();

    return 0;
}
