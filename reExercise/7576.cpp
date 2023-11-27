
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int M, N;
int map[MAX][MAX];
bool visit[MAX][MAX];
int input[MAX][MAX];
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

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (visit[nx][ny] == 0) {
                    map[nx][ny] = map[x][y] + 1;
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (input[i][j] == 1) {
                map[i][j] = 0;
                visit[i][j] = true;
                q.push({i,j});
            }
            else if (input[i][j] == -1) {
                visit[i][j] = true;
            }
        }
    }
    BFS();

    int ans = -1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && input[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (map[i][j] > ans) {
                ans = map[i][j];
            }
        }
    }

    cout << ans;

}