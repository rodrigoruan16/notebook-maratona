void dfs(int v) {
    if (visited[v])
        return;

    visited[v] = 1;

    for (int c : G[v]) {
        if (!visited[c])
            dfs(c);
    }
}