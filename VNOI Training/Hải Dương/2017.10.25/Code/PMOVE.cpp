#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e5 + 10;

int n;
int f[N], cnt[N][66];
bool have[N];
vector <int> prime;

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (!f[i]) {
            f[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < sz(prime) && i * prime[j] < N && prime[j] <= f[i]; ++j)
            f[i * prime[j]] = prime[j];
    }
}

int main() {
    freopen("PMOVE.inp", "r", stdin);
    freopen("PMOVE.out", "w", stdout);

    sieve(); //cerr << sz(prime) << "\n";
    scanf("%d", &n); for (int i = 0; i < sz(prime); ++i) cnt[prime[i]][0] = n;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        while (x != 1) {
            int y = f[x], c = 0;
            while (x % y == 0) x /= y, c++;
            cnt[y][c]++; cnt[y][0]--;
            have[y] = 1;
        }
    }

    int ans = 0, pos = 1;
    for (int i = 0; i < sz(prime); ++i) if (have[prime[i]]) {
        int cura = 0, curb = 0, id = 0;
        for (int j = 0; j <= 64; ++j) {
            cura += cnt[prime[i]][j];
            if (cura >= n / 2) {
                id = j;
                break;
            }
        }
        cura = 0;
        for (int j = 0; j <= 64; ++j) if (j != id) {
            cura += cnt[prime[i]][j] * abs(j - id);
        }
        int jd = id + 1;
        for (int j = 0; j <= 64; ++j) if (j != jd) {
            curb += cnt[prime[i]][j] * abs(j - jd);
        }
        if (curb < cura) swap(id, jd);
        while (id--) pos *= prime[i];
        ans += min(cura, curb);
    }
    printf("%d %d\n", ans, pos);

    return 0;
}
