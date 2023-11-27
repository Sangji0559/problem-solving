#include<iostream>
#include<queue>

using namespace std;

int map[1001][1001];
int input[1001][1001];
bool visit[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
int n, m;

void bfs() {
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] == false) {
					map[nx][ny] = map[x][y] + 1;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				map[i][j] = 0;
				visit[i][j] = true;
				q.push({ i,j });
			}
			else if (input[i][j] == 0) {
				visit[i][j] = true;
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == false) {
				printf("-1 ");
			}
			else
				printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}