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

int n, k;
int st[2][N], a[N], head[2], tail[2];

void load() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) read(a[i]);
}

void process() {
    int ans = 0; head[0] = head[1] = 0; tail[0] = tail[1] = -1;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (head[0] <= tail[0] && a[st[0][tail[0]]] > a[i]) tail[0]--;
        st[0][++tail[0]] = i;
        while (head[1] <= tail[1] && a[st[1][tail[1]]] < a[i]) tail[1]--;
        st[1][++tail[1]] = i;
        while (j < i && a[st[1][head[1]]] - a[st[0][head[0]]] > k) {
            j++;
            while (head[0] <= tail[0] && st[0][head[0]] < j) head[0]++;
            while (head[1] <= tail[1] && st[1][head[1]] < j) head[1]++;
        }
        ans = max(ans, i - j + 1);
    }
    writeln(ans);
}

int main() {
    freopen("AF7.inp", "r", stdin);
    freopen("AF7.out", "w", stdout);

    load();
    process();

    return 0;
}
