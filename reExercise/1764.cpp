#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> m;
	vector<string> answer;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		string name;
		cin >> name;
		m[name]++;
	}
	for (auto it : m) {
		if (it.second == 2) answer.push_back(it.first);
	}

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	
}