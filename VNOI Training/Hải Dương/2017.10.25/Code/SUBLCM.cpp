#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int a[N], f[N];
bool exis[N];
vector <int> prime;

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (!f[i]) {
            f[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < (int) prime.size() && prime[j] <= f[i] && i * prime[j] < N; ++j)
            f[i * prime[j]] = prime[j];
    }
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}

bool ok(int x) {
    while (x != 1) {
        int p = f[x];
        if (exis[p]) return 0;
        while (x % p == 0) x /= p;
    }
    return 1;
}

void update(int x, int v) {
    while (x != 1) {
        int p = f[x];
        exis[p] = v;
        while (x % p == 0) x /= p;
    }
}

void process() {
    memset(exis, 0, sizeof exis);
    int ans = 1;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (!ok(a[i]) && j < i) {
            update(a[j++], 0);
        }
        ans = max(ans, i - j + 1);
        update(a[i], 1);
      //  cerr << j << " " << i << "\n";
    }
   // cerr << "\n";
    if (ans == 1) puts("-1"); else printf("%d\n", ans);
}

int main() {
    freopen("SUBLCM.inp", "r", stdin);
    freopen("SUBLCM.out", "w", stdout);

    sieve();
    int t; scanf("%d", &t);
    while (t--) {
        load();
        process();
    }

    return 0;
}
