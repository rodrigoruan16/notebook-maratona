#include <bits/stdc++.h>
 
using namespace std;

vector<vector<int>> G;
vector<int> visited;
vector<int> teams;

int bfs(int i) {
    queue<int> q;
    q.push(i);

    teams[i] = 1;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (visited[c])
            continue;

        visited[c] = 1;

        for (int p : G[c]) {
            if (visited[p])
                continue;

            if (teams[p] == teams[c]) {
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }

            teams[p] = (teams[c] == 1 ? 2 : 1);
            q.push(p);
        }      
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    G = vector<vector<int>>(n + 1, vector<int>());
    teams = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (teams[i] != 0)
            continue;

        if (!bfs(i))
            return 0;
    }

    for (int i = 1; i <= n; i++)
        cout << teams[i] << ' ';
    cout << '\n';

    return 0;
}