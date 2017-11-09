#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e6 + 10, MOD = 111539786;

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
    freopen("LCM.inp", "r", stdin);
    freopen("LCM.out", "w", stdout);

    sieve();
    scanf("%d", &n);
    while (n--) {
        int a, b; scanf("%d%d", &a, &b); a--;
        map <int, int> p;
        for (int i = 0; i < sz(prime) && prime[i] <= b; ++i) {
            int cnt = 0;
            for (int x = b; x / prime[i] > 0; x /= prime[i]) cnt += x / prime[i];
            p[prime[i]] += cnt;
        }
        for (int i = 0; i < sz(prime) && prime[i] <= b; ++i) {
            int cnt = 0;
            for (int x = a; x / prime[i] > 0; x /= prime[i]) cnt += x / prime[i];
            p[prime[i]] -= cnt;
        }
        int ans = 1;
        for (pair <int, int> it : p) if (it.second != 0) {
           // cerr << it.first << " " << it.second << "\n";
            ans = 1ll * ans * (it.second * 2 + 1) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}
