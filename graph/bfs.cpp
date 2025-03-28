#include <bits/stdc++.h>
 
using namespace std;

// BFS COM PREVIOUS DO LABYRINTH CSES

vector<vector<char>> G;
vector<vector<int>> visited;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<pair<int, int>>> previous;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (visited[p.first][p.second])
            continue;

        if (G[p.first][p.second] == 'B') {
            return;
        }

        visited[p.first][p.second] = 1;

        for (pair<int, int> pp : moves) {
            int I = p.first + pp.first, J = p.second + pp.second;

            if (I < 0 || J < 0 || I >= G.size() || J >= G[0].size() || visited[I][J] || G[I][J] == '#')
                continue;

            previous[I][J] = {p.first, p.second};
            q.push({I, J});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    G = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<int>>(n, vector<int>(m, 0));
    previous = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));

    int beginI = 0, beginJ = 0, finalI = 0, finalJ = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'A') {
                beginI = i;
                beginJ = j;
            }

            if (G[i][j] == 'B') {
                finalI = i;
                finalJ = j;
            }
        }
    }

    previous[finalI][finalJ] = {INT_MIN, INT_MAX};

    bfs(beginI, beginJ);

    if (previous[finalI][finalJ].first == INT_MIN && previous[finalI][finalJ].second == INT_MAX) {
        cout << "NO" << "\n";
        return 0;
    }

    cout << "YES\n";

    stack<char> ans;

    while (finalI != beginI || finalJ != beginJ) {
        pair<int, int> &pre = previous[finalI][finalJ];

        if (finalI < pre.first)
            ans.push('U');
        else if (finalI > pre.first)
            ans.push('D');
        else if (finalJ < pre.second)
            ans.push('L');
        else
            ans.push('R');

        finalI = pre.first;
        finalJ = pre.second;
    }

    cout << ans.size() << '\n';

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}