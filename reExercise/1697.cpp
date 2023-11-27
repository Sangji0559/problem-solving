#include<iostream>
#include<queue>

using namespace std;
bool visit[100001];
int n, k;

int bfs(int n, int m) {
    int time = 0;
    queue<int> q;
    q.push(n);

    while (1) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            n = q.front();
            q.pop();
            if (n == k)
                return time;
            if (n > 0 && visit[n - 1] == 0) {
                q.push(n - 1);
                visit[n - 1] = 1;
            }
            if (n < 100000 && visit[n + 1] == 0) {
                q.push(n + 1);
                visit[n + 1] = 1;
            }
            if (n * 2 <= 100000 && visit[n * 2] == 0) {
                q.push(n * 2);
                visit[n * 2] = 1;
            }
        }
        time++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}