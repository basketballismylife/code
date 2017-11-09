#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

typedef pair <int, long long> ii;

const int N = 1e6 + 10;

int n, k;
ii A[N], p[N];

void load() {
    read(n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        sum += x;
        A[i] = make_pair(i, sum);
    }
}

ii operator - (ii a, ii b) { return make_pair(b.first - a.first, b.second - a.second); }
long long operator * (ii a, ii b) { return a.first * b.second - a.second * b.first; }

bool ccw(ii a, ii b, ii c) { return (b - a) * (c - b) > 0; }

void findConvexLine() {
    for (int i = 0; i <= n; ++i) {
        while (k > 1 && !ccw(p[k - 2], p[k - 1], A[i])) k--;
        p[k++] = A[i];
    //    cerr << A[i].first << " " << A[i].second << "\n";
    }
   // cerr << "\n";
    //for (int i = 0; i < k; ++i) cerr << p[i].first << " " << p[i].second << "\n";
}

void process() {
    findConvexLine();
    long double S = 0, P = 0;
    for (int i = 0; i < n; ++i)
        S += A[i].second + (A[i + 1].second - A[i].second) * 0.5;
    for (int i = 0; i < k - 1; ++i)
        P += p[i].second * (p[i + 1].first - p[i].first) + (p[i + 1].second - p[i].second) * (p[i + 1].first - p[i].first) * 0.5;
    cerr << S << " " << P << "\n";
    printf("%.1lf\n", S - P);
}

int main() {
    freopen("WATERMOV.inp", "r", stdin);
    freopen("WATERMOV.out", "w", stdout);;

    load();
    process();

    return 0;
}
