#include<iostream>
#include<queue>

using namespace std;
int n, m;
int map[101][101];
int dist[101];
queue<int> q;

void BFS(int start) {
	q.push(start);
	fill_n(dist, 101, -1);
	dist[start]++;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (dist[i] >= 0 || map[current][i] != 1) continue;
			q.push(i);
			dist[i] = dist[current] + 1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int min = 1e9, index = -1;
	for (int i = 1; i <= n; i++) {
		BFS(i);
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[j];
		}
		if (min > sum) {
			min = sum;
			index = i;
		}
	}
	cout << index;
	return 0;
}