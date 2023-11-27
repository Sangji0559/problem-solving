#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int N, M;

string name[100001];
map<string, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		name[i] = s;
		m.insert(make_pair(s, i));
	}
	for (int i = 1; i <= M; i++) {
		string s;
		int n;
		cin >> s;
		if (s[0]-48>0&&s[0]-48<10) {
			n = stoi(s);
			cout << name[n] << "\n";
		}
		else {
			auto it = m.find(s);
			cout << it->second << "\n";
		}
	}
}