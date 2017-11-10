//mảng d[] là mảng tính số nhịp bé nhất của đường tăng luồng giữa đỉnh chưa ghép với đỉnh đã ghép
bool FindPath() {
	int head = 1, tail = 0;
	for (int u = 1; u <= m; ++u) if (ft[u] == 0) {
		q.push(u); d[u] = 0;
	} else {
		d[u] = m + 1;
	}
	d[0] = m + 1;
	while (head <= tail) {
		int u = q[head++];
		for (int v : adj[u]) if (ft[u] != v) {
			w = fp[v];
			if (d[w] == m + 1) {
				d[w] = d[u] + 1;
				q[++tail] = w;
			}
		}
	}
	return d[0] < m + 1;
}

bool ghep (int u) {
	if (u == 0) return 1;
	for (int v : adj[u]) {
		w = fp[v];
		if (d[w] == d[u] + 1) {
			if (ghep(w)) {
				ft[u] = v;
				fp[v] = u;
				return 1;
			}
		}
	}
	d[u] = m + 1;
	return 0;
}

void process() {
	memset(ft, 0, sizeof ft); memset(fp, 0, sizeof fp);
	long long mf = 0;
	while (FindPath()) {
		for (int u = 1; u <= m; ++u) if (d[u] = 0 && ghep(u)) ++ mf;
	}
	printf("%d\n", mf);
}

int main() {
	freopen("FMATCH.inp", "r", stdin);
	freopen("FMATCH.out", "w", stdout);
	
	load();
	
	
}