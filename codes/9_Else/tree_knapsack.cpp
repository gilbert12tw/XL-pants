void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : tree[u]) if (v != p) {
    dfs(v, u);
    for (int i = sz[u] + sz[v]; i >= 1; i--)
      for (int j = max(1, i - sz[u]); j<=i && j<=sz[v]; j++)
        dp[u][i] = min(dp[u][i], dp[u][i-j] + dp[v][j]);	
    sz[u] += sz[v];
  }
}
