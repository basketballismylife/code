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

int n, head, tail;
int a[N], l[N], r[N], st[N], ans[N];

int main() {
    freopen("AF12.inp", "r", stdin);
    freopen("AF12.out", "w", stdout);

    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);

    head = 0; tail = -1;
    for (int i = 1; i <= n; ++i) {
        l[i] = 0; r[i] = n + 1;
        while (head <= tail && a[st[tail]] >= a[i]) {
            r[st[tail--]] = i;
        }
        if (head <= tail) l[i] = st[tail];
        st[++tail] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int k = r[i] - l[i] - 1; //cerr << i << " " << l[i] << " " << r[i] << "\n";
        ans[k] = max(ans[k], a[i]);
    }
    for (int i = n - 1; i > 0; --i) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; ++i) write(ans[i]), putchar(' ');

    return 0;
}
