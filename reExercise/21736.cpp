#include <iostream>
#include <queue>
using namespace std;

const int MAX = 601;
int M, N; // 가로 세로
bool visit[MAX][MAX]; 
char input[MAX][MAX]; 
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int ans;
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
                if (visit[nx][ny] == 0) { // 방문하지 않았을 경우
                    visit[nx][ny] = true; // 방문한 것으로 체크
                    if (input[nx][ny] == 'P') {
                        cout << nx << " " << ny << "\n";
                        ans++;
                    }
                    q.push({ nx,ny }); // 큐에 삽입하여 재귀
                }
            }

        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (input[i][j] == 'I') { 
                visit[i][j] = true; 
                q.push({ i,j }); 
            }
            else if (input[i][j] == 'X') {
                visit[i][j] = true; 
            }
        }
    }
    BFS(); // 너비 우선 탐색

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << input[i][j] << " ";
        }
        cout << "\n";
    }
    if (ans != 0) {
        cout << ans;
    }
    else
        cout << "TT";

    return 0;
}