#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<int> visited;


// 일반적인 dfs 사용
void dfs(int x)
{
    if (visited[x] == 1) return;
    visited[x] = 1;

    for (int i = 0; i < vec[x].size(); i++)
    {
        dfs(vec[x][i]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // vector 사용을 위해 resize
    vec.resize(n + 1);
    visited.resize(n + 1);

    // 방향없는 양방향 간선이므로
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }


    // 숫자를 세기 위한 count
    int count = 0;
    // 1번 노드부터 n번 노드까지 다 dfs를 돌리는데,
    // 이미 방문한 노드라면 넘어간다.
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 1) continue;
        dfs(i);
        count++;
    }

    // 연결 요소의 개수를 출력
    cout << count;

    return 0;
}