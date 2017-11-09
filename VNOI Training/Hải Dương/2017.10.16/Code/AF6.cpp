#include <bits/stdc++.h>
using namespace std;

template <class T> void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') nega = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> wri(T x) { if (x / 10) wri(x / 10); putchar(x % 10 + '0'); }
template <class T> write(T x) { if (x < 0) putchar('-'); wri(abs(x)); }
template <class T> writeln(T x) { write(x); putchar('\n'); }
const int N = 1e6 + 10;

int n, m;
int a[N], incr[N];

int main() {
    freopen("AF6.inp", "r", stdin);
    freopen("AF6.out", "w", stdout);

    while (1) {
        read(n);
        if (!n) break;
        for (int i = 1; i <= n; ++i) read(a[i]);
        scanf("%d", &m);
        memset(incr, 0, sizeof incr);
        for (int i = 1; i <= m; ++i) {
            int u, v, w; read(u); read(v); read(w);
            incr[u] += w; incr[v + 1] -= w;
        }
        for (int i = 1; i <= n; ++i) {
            incr[i] += incr[i - 1];
            write(a[i] + incr[i]); putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
