#include <bits/stdc++.h>
using namespace std;

const int N = 222;

int n, m;
char s[N], t[N], z[N];

void load() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
}

void process() {
    int ans = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < 1 << (m - 1); ++mask) {
            int x = 0;
            for (int j = i; j < n; ++j) z[x++] = s[j];
            for (int j = 0; j < i; ++j) z[x++] = s[j];

            for (int j = 0; j < m - 1; ++j) if (mask >> j & 1) {
                for (int k = 0; k < m; ++k) z[(j + k) % n] = '1' - z[(j + k) % n] + '0';
            }
            int cnt = 0;
            for (int j = m - 1; j < n; ++j) {
                if (z[j] != t[j]) {
                    cnt++;
                    for (int k = 0; k < m; ++k) {
                        z[(j + k) % n] = '1' - z[(j + k) % n] + '0';
                    }
                }
            }
            bool ok = 1;
            for (int j = 0; j < n; ++j) if (z[j] != t[j]) {
                ok = 0;
                break;
            }
            if (ok) {
                //if (cnt + __builtin_popcount(mask) == 1) cerr << i << " " << mask << "\n";
                ans = min(ans, cnt + __builtin_popcount(mask));
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("Latco.inp", "r", stdin);
    freopen("Latco.out", "w", stdout);

    load();
    process();

    return 0;
}
