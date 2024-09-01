int n, q, tk, sz[mxN], fa[mxN], bson[mxN], tp[mxN], dep[mxN], dfn[mxN];
// hson -> big son
// tp -> top of chain
vector<int> g[mxN];
 
void dfs(int u, int p) { 
	sz[u] = 1;
	fa[u] = p;
	bson[u] = -1;
	for (int v : g[u]) {
		if(v == p) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if(bson[u] == -1 || sz[v] > sz[bson[u]]) bson[u] = v;
	}
}
 
void link(int u, int p) {
	tp[u] = p;
	dfn[u] = ++tk;
	if(bson[u] != -1) link(bson[u], p);
	for(int v : g[u]) {
		if(v == fa[u] || v == bson[u]) continue;
		link(v, v);
	}
}

void jump(int a, int b) {
	int ans = 0;
	while(tp[a] != tp[b]) {
		if(dep[tp[a]] < dep[tp[b]]) swap(a, b);
	    // do someting to [dfn[tp[a]], dfn[a]]
		a = fa[tp[a]];
	}
	if(dfn[a] > dfn[b]) swap(a, b);
	// don't forget [dfn[a], dfn[b]]
}
