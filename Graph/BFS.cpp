#include <bits/stdc++.h>
 
using namespace std;

vector<vector<int>> G;
vector<int> visited;
vector<int> pred;

// BFS COM PREDECESSOR LISTA ADJ

void bfs(int i) {
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        if (visited[a])
            continue;

        visited[a] = 1;

        for (int p : G[a]) {
            if (!visited[p]) {
                q.push(p);
                if (pred[p] == -1)
                    pred[p] = a;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(0);

    int n, m;
    cin >> n >> m;

    G = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<int>(n + 1, 0);
    pred = vector<int> (n + 1, -1);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bfs(1);

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int p = pred[n];
    stack<int> s;
    s.push(n);

    while (p != -1) {
        s.push(p);
        p = pred[p];
    }

    cout << s.size() << '\n';

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << '\n';

    return 0;
}