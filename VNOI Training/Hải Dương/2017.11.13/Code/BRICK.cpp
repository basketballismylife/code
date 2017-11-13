#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct matrix {
    int m, n;
    long long a[2][2];

    matrix operator * (const matrix &p) {
        matrix e; e.m = this->m; e.n = p.n;
        for (int i = 0; i < e.m; ++i) for (int j = 0; j < e.n; ++j) {
            e.a[i][j] = 0;
            for (int k = 0; k < this->n; ++k)
                e.a[i][j] = (e.a[i][j] + this->a[i][k] * p.a[k][j]) % MOD;
        }
        return e;
    }
    matrix operator ^ (int k) {
        matrix e; e.m = this->m; e.n = this->n;
        matrix p = *this;
        for (int i = 0; i < e.m; ++i) for (int j = 0; j < e.n; ++j) e.a[i][j] = i == j;
        while (k) {
            if (k & 1) e = e * p;
            p = p * p;  k >>= 1;
        }
        return e;
    }
};

matrix a, b, c;

void init() {
    a.m = a.n = 2;
    a.a[0][0] = a.a[0][1] = a.a[1][0] = 1; a.a[1][1] = 0;
    b.m = 2; b.n = 1;
    b.a[0][0] = 1; b.a[1][0] = 1;
}

int main() {
    freopen("BRICK.inp", "r", stdin);
    freopen("BRICK.out", "w", stdout);

    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        init();
        a = a ^ (n - 1);
        c = a * b;
        printf("%lld\n", c.a[0][0]);
    }

    return 0;
}
