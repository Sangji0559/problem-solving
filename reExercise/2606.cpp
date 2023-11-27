#include<iostream>

using namespace std;

#define max 101
int map[max][max] = { 0 };
bool visit[max] = { 0 };
int V, E;
int ans = 0;

void DFS(int v) {
	visit[v] = 1;
	ans++;
	for (int i = 1; i <= V; i++) {
		if (visit[i] == 0 && map[v][i] == 1) {
			DFS(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(1);
	cout << ans - 1;
}