// Calcula o número mínimo de operações necessárias para transformar uma string em outra.
#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios::sync_with_stdio(0);cin.tie(0);
 
int main() { _
	string a, b;
	cin >> a >> b;

	vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));

	for (int i = 0; i <= a.size(); i++)
		dist[i][0] = i;
	for (int i = 0; i <= b.size(); i++)
		dist[0][i] = i;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1])
				dist[i][j] = dist[i-1][j-1];
			else
				dist[i][j] = 1 + min({
					dist[i-1][j],
					dist[i][j-1],
					dist[i-1][j-1]
				});
		}
	}

	cout << dist[a.size()][b.size()] << "\n";

	return 0;
}