#include <iostream>
#include <queue>
using namespace std;

int N, M, V; //��������, ��������, ��������
int map[1001][1001]; //���� ��� �׷���
bool visited[1001]; //���� �湮 ����
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
            DFS(i);
        }
    }
}

void BFS() {
    while (!q.empty()) {
        int v = q.front();
        for (int i = 1; i <= N; i++) {
            if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
        q.pop();
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    reset();
    DFS(V);

    cout << '\n';

    reset();
    q.push(V);
    visited[V] = true;
    cout << V << " ";
    BFS();

    return 0;
}
