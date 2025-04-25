#include <bits/stdc++.h>
 
using namespace std;

vector<vector<char>> G;
vector<vector<int>> visited;
vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs(int i, int j) {
    if (visited[i][j])
        return;

    visited[i][j] = 1;

    for (pair<int, int> p : moves) {
        int I = i + p.first, J = j + p.second;

        if (I < 0 || J < 0 || I >= G.size() || J >= G[0].size())
            continue;

        dfs(I, J);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    G = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    return 0;
}