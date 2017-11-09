/*
    Author: houtaru
    Create: 22.10.2017
    Status: WA
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, head, tail;
int a[N << 1], st[N << 1];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
}

void process() {
    for (int i = 1; i <= 2 * n; ++i) a[i] += a[i - 1];//, cerr << a[i] << " "; cerr << "\n";
    head = 0; tail = 0;  st[0] = 0;
    int ans = -(1 << 31) + 1;
    for (int i = 1; i <= 2 * n; ++i) {
        while (head <= tail && i - st[head] > n) head++;
        ans = max(ans, a[i] - a[st[head]]); //cerr << st[head] << " " << i << "\n";
        while (head <= tail && a[st[tail]] > a[i]) tail--;
        st[++tail] = i;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("AF2.inp", "r", stdin);
    freopen("AF2.out", "w", stdout);

    load();
    process();

    return 0;
}
