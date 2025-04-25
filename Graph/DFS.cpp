#include <bits/stdc++.h>
 
using namespace std;

vector<vector<int>> G;
vector<int> visited;

void dfs(int city) {
    stack<int> st;
    st.push(city);

    while (!st.empty()) {
        int c = st.top();
        st.pop();

        if (visited[c])
            continue;

        visited[c] = 1;

        for (int p : G[c]) {
            if (!visited[p])
                st.push(p);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    G = vector<vector<int>>(n + 1, vector<int>());

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int total = 0;

    string ans;
    visited = vector<int>(n + 1, 0);

    return 0;
}