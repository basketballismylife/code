#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long c[33][33];

int main() {
    freopen("SET.inp", "r", stdin);
    freopen("SET.out", "w", stdout);

    c[0][0] = 1;
    for (int i = 1; i < 32; ++i) for (int j = 0; j < 32; ++j) {
        c[i][j] = c[i - 1][j];
        if (j > 0) c[i][j] += c[i - 1][j - 1];
    }
    while (~scanf("%d%lld", &n, &m)) {
        int p;
        for (p = 0; p <= n; ++p) if (m > c[n][p]) {
            m -= c[n][p];
        } else break;

        vector <int> ans;
        for (int i = 1; i <= n; ++i) {
            if (p == 0) {
                ans.push_back(2);
                continue;
            }
            if (m <= c[n - i][p - 1]) {
                ans.push_back(3);
                p--;
            } else {
                ans.push_back(2);
                m = m - c[n - i][p - 1];
            }
        }
        long long answer = 1;
        for (int v : ans) answer = answer * v + 1;
        printf("%lld\n", answer);
    }

    return 0;
}
