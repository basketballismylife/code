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

int t, a, b;
int f[N];
vector <int> prime;
long long cnt[N], sum[N];

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

int main() {
    freopen("US.inp", "r", stdin);
    freopen("US.out", "w", stdout);

    sieve();
    cnt[1] = 1;
    for (int i = 2; i < N; ++i) {
        int p = f[i], x = i, c = 0;
        while (x % p == 0) c++, x /= p;
        cnt[i] = (c + 1) * cnt[x];
        //if (i <= 10) cerr << i << " " << p << " " << c << " " << (c + 1) * cnt[x] << "\n";
    }
    //cerr << "\n";
    sum[1] = 1;
    for (int i = 2; i < N; ++i) {
        int p = f[i], x = i, t = 1;
        while (x % p == 0) x /= p, t = t * p + 1;
        //if (i <= 10) cerr << i << " " << sum[x] * t << "\n";
        sum[i] = t * sum[x];
    }
    for (int i = 1; i < N; ++i) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    int q; read(q);
    while (q--) {
        int a, b; read(a); read(b);
        write(cnt[b] - cnt[a - 1]); putchar(' '); writeln(sum[b] - sum[a - 1]);
    }

    return 0;
}
