#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, b, p;
int a[N];
map <int, int> f;

void load() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] == b) p = i;
    }
}

void process() {
    a[p] = 0;
    for (int i = p - 1; i > 0; --i)
        a[i] = a[i + 1] + (a[i] > b ? 1 : -1);
    for (int i = p + 1; i <= n; ++i)
        a[i] = a[i - 1] + (a[i] > b ? 1 : -1);
   // for (int i = 1; i <= n; ++i) cerr << a[i] << "\n";
 //   cerr << p << "\n";
    int ans = 0;
    for (int i = 1; i <= p; ++i) {
        ans += !a[i];
        f[a[i]]++;
    }
    for (int i = p + 1; i <= n; ++i) {
        ans += f[-a[i]];
    }
    printf("%d\n", ans);
}

int main() {
    freopen("ODDSEQ.inp", "r", stdin);
    freopen("ODDSEQ.out", "w", stdout);

    load();
    process();

    return 0;
}
