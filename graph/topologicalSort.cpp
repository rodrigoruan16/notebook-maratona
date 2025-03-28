#include <bits/stdc++.h>
 
using namespace std;

// TOPOLOGICAL SORT FROM COURSE SCHEDULE (CSES) USING DFS
// IT ALREADY CHECKS IF THERE IS A CYCLE

vector<vector<int>> G;
vector<int> visited;
vector<int> visitedPath;
stack<int> topological;

void dfs(int i, int path, int &ok) {
    if (visited[i])
        return;

    visited[i] = 1;
    visitedPath[i] = path;

    for (int p : G[i]) {
        if (visited[p] && visitedPath[p]) {
            ok = 0;
            return;
        }

        if (!visited[p]) {
            dfs(p, path, ok);
        }
    }

    visitedPath[i] = 0;
    topological.push(i);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;

    G = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<int>(n + 1, 0);
    visitedPath = vector<int> (n + 1, 0);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        int ok = 1;
        dfs(i, i, ok);

        if (!ok) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    while (!topological.empty()) {
        int c = topological.top();
        topological.pop();

        cout << c << ' ';
    }

    return 0;
}