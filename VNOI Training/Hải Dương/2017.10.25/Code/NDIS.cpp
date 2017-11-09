#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

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

int a, b;
int f[N], A[N], B[N];
bool have[N];
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
    freopen("NDIS.inp", "r", stdin);
    freopen("NDIS.out", "w", stdout);

    sieve();
    int iTest = 0;
    while (1) {
        iTest++;
        read(a); read(b);
        if (!a && !b) break;
        vector <int> p;
        while (a != 1) {
            int x = f[a], c = 0;
            while (a % x == 0) c++, a /= x;
            A[x] += c;
            if (!have[x]) {
                p.push_back(x);
                have[x] = 1;
            }
        }
        while (b != 1) {
            int x = f[b], c = 0;
            while (b % x == 0) c++, b /= x;
            B[x] += c;
            if (!have[x]) {
                p.push_back(x);
                have[x] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < sz(p); ++i) {
            int v = p[i];
            ans += abs(A[v] - B[v]);
            A[v] = B[v] = have[v] = 0;
        }
        printf("%d. %d:%d\n", iTest, sz(p), ans);
    }

    return 0;
}
