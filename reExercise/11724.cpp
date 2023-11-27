#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<int> visited;


// �Ϲ����� dfs ���
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

    // vector ����� ���� resize
    vec.resize(n + 1);
    visited.resize(n + 1);

    // ������� ����� �����̹Ƿ�
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }


    // ���ڸ� ���� ���� count
    int count = 0;
    // 1�� ������ n�� ������ �� dfs�� �����µ�,
    // �̹� �湮�� ����� �Ѿ��.
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 1) continue;
        dfs(i);
        count++;
    }

    // ���� ����� ������ ���
    cout << count;

    return 0;
}