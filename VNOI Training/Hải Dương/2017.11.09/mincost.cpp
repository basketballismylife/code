//mincost
for (int i = 1; i <= n; ++i) {
	findPath();
	incFlow();
}

void findPath() {
	for (int u = 0; u <= n; ++u) kc[u] = INF, cl[u] = 0;
	q.clear();
	for (int u = 1; u <= n; ++u) if (ft[u] == 0 [
		q.push(u); cl[u] = 1; kc[u] = 0;
		while (!q.empty()) {
			int u = q.top(); q.pop(); cl[u] = 0;
			for (int v : adj[u]) if (ft[u] != v) {
				int w = fp[v], L = a[u][v] - a[w][v];
				if (kc[w] > kc[u] + L) {
					prv[w] = u;
					kc[w] = kc[u] + L;
					if (!cl[w]) {
						q.push(w);
						cl[w] = 1; ft[w] = v;
					}
				}
			}
		}
	)
}

void incFlow() {
	int u = prv[0]; v = ft[v];
	while (u != n + 1) {
		int w = ft[u];
		ft[u] = v; ft[v] = u;
		u = prv[u]; v = w;
	}
}