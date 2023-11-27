#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int N, M;
map<string, string> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	string domain;
	string pwd;
	for (int i = 0; i < N; i++) {
		cin >> domain >> pwd;
		m.insert(make_pair(domain, pwd));
	}

	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		auto it = m.find(temp);
		cout << it->second << "\n";
	}

}