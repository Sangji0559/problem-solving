#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int MAX = 51;
int t, n, m, k; //입력 값
int arr[MAX][MAX];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool visited[MAX][MAX];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (visited[nx][ny])
            continue;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (arr[nx][ny] == 0)
            continue;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}
int main()
{
    cin >> t;
    while (t--) {
        memset(visited, false, sizeof(visited)); //방문노드 초기화
        memset(arr, 0, sizeof(arr)); //입력배열 초기화
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++; //dfs로 한번 순회하면 카운트 증가
                }
            }
        }
        cout << cnt << endl;
    }
}