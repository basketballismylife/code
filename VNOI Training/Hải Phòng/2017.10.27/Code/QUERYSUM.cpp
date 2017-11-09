#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, q;
int a[N];
long long t[N];

void update(int x, int value) {
    for (; x < N; x += x & -x)
        t[x] += value;
}

long long get(int x) {
    long long res = 0;
    for (; x > 0; x -= x & -x)
        res += t[x];
    return res;
}

int main() {
    freopen("QUERYSUM.inp", "r", stdin);
    freopen("QUERYSUM.out", "w", stdout);

    scanf("%d%d", &n, &q);
    while (q--) {
        char s[2]; int x, y; scanf("%s%d%d", s, &x, &y);
        if (s[0] == 'S') {
            update(x, y - a[x]);
            a[x] = y;
        } else {
            printf("%lld\n", get(y) - get(x - 1));
        }
    }

    return 0;
}
