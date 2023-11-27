#include<iostream>
#include<queue>

using namespace std;
int n, m;
string map[101];
int dist[101][101]; 
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == 0 && map[nx][ny] == '1') {
                q.push({ nx,ny });
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> m;
	for (int i = 0; i < n; i++) {
        cin >> map[i];
	}
    dist[0][0] = 1;
    q.push({ 0,0 });
    BFS();
    cout << dist[n - 1][m - 1];

	return 0;
}