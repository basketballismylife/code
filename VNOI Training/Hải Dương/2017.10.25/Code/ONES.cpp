#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e6 + 10;

int n;
int f[N];
vector <int> prime;

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (!f[i]) {
            f[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < sz(prime) && prime[j] <= f[i] && i * prime[j] < N; ++j)
            f[i * prime[j]] = prime[j];
    }
}

int main() {
    freopen("ONES.inp", "r", stdin);
    freopen("ONES.out", "w", stdout);

    sieve();
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        map <int, int> g;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            while (x != 1) {
                int y = f[x], c = 0;
                while (x % y == 0) x /= y, c++;
                if (!g.count(y) || g[y] < c) g[y] = c;
            }
        }
        int ans = 0;
        for (pair <int, int> it : g)
            ans += it.second;
        printf("%d\n", ans);
    }

    return 0;
}
