#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,cnt=0; // 길이 입력
string map[26]; // 입력값 붙어서 들어옴
bool dist[26][26]; // 방문여부 체크
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
vector<int> result;
queue<pair<int, int>> q;

void BFS(int x, int y) {
	cnt = 0;
	q.push({ x,y });
	dist[x][y] = true;
	cnt++;

	while (!q.empty()) {
		int fir = q.front().first;
		int sec = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fir + dx[i];
			int ny = sec + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == 0 && map[nx][ny] == '1') {
				q.push({ nx,ny });
				dist[nx][ny] = true;
				cnt++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == false && map[i][j] == '1') {
				BFS(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}