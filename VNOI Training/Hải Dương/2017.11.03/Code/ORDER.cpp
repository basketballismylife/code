#include <bits/stdc++.h>
using namespace std;

template <class T> T offBit(T x, int k) { return x ^ (1 << k);}
const int N = 22;

int n;
int f[1 << 16];
int s[N][N];

void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
        scanf("%d", &s[i][j]);
}

void process() {
    for (int mask = 0; mask < 1 << n; ++mask) {
        f[mask] = - 1;
        for (int i = 0; i < n; ++i) if (mask >> i & 1) {
            int masku = offBit(mask, i), cur = f[masku] + s[i][i];
            for (int j = 0; j < n; ++j) if (masku >> j & 1)
                cur += s[i][j];
            f[mask] = f[mask] == -1 ? cur : min(f[mask], cur);
        }
        if (f[mask] == -1) f[mask] = 0;
    }
   // for (int i = 0; i < 1 << n; ++i) cerr << f[i] << "\n";
    printf("%d\n", f[(1 << n) - 1]);
}

int main() {
    freopen("ORDER.inp", "r", stdin);
    freopen("ORDER.out", "w", stdout);

    load();
    process();

    return 0;
}
