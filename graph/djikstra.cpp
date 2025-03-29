#include <bits/stdc++.h>
 
using namespace std;

vector<vector<pair<int, int>>> G;
vector<int> visited;
vector<int> dist;

void dijkstra(int i) {
    priority_queue<pair<int, int>> q;
    dist[i] = 0;
    q.push({0, i});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();

        if (visited[a])
            continue;
        
        visited[a] = 1;

        for (pair<int, int> p : G[a]) {
            int b = p.first, w = p.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({ -dist[b], b });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(0); // remove when working with floating point

    int n, m;
    cin >> n >> m;

    G = vector<vector<pair<int, int>>> (n + 2, vector<pair<int ,int>>());
    visited = vector<int> (n + 2, 0);
    dist = vector<int> (n + 2, INFINITY);

    int s, t, b;
    while (m--) {
        cin >> s >> t >> b;
        G[s].push_back({t, b});
        //G[t].push_back({s, b});
    }

    dijkstra(0);

    cout << dist[n + 1] << '\n';

    return 0;
}