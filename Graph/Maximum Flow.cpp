//The max flow problem is a classic optimization problem in graph theory that involves finding the maximum amount of flow that can be sent through a network of pipes, channels, or other pathways, subject to capacity constraints. The problem can be used to model a wide variety of real-world situations, such as transportation systems, communication networks, and resource allocation.

#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios::sync_with_stdio(0);cin.tie(0);

vector<vector<int>> capacity;
vector<vector<int>> G;

int bfs(int s, int t, vector<int> &parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT_MAX});

	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int next : G[cur]) {
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push({ next, new_flow });
			}
		}
	}

	return 0;
}

int maxflow(int s, int t) {
	int flow = 0;
	vector<int> parent(G.size());
	int new_flow;

	while (new_flow = bfs(s, t, parent)) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}
 
int main() { _
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;

	G = vector<vector<int>>(n + 1, vector<int>());
	capacity = vector<vector<int>>(n+1, vector<int>(n+1, 0));

	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		capacity[u][v] += w;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	cout << maxflow(s, t) << "\n";

	return 0;
}