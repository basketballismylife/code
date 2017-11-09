#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int m, n, q;
int row[N], col[N];
vector < vector <int> > a;

void load() {
    scanf("%d%d%d", &m, &n, &q);
    a = vector < vector <int> > (m + 1, vector <int>(n + 1));
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    while (q--) {
        int u; scanf("%d", &u);
        if (u > m)
            col[u - m] = (col[u - m] + 1) % 3;
        else
            row[u] = (row[u] + 1) % 3;
    }
}

void process() {
    int ans = 0;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j)
        ans += (a[i][j] + col[j] + row[i]) % 3 == 0;
    printf("%d\n", ans);
}

int main() {
    freopen("LISYS.inp", "r", stdin);
    freopen("LISYS.out", "w", stdout);

    load();
    process();

    return 0;
}
