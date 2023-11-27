#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	int T, N;
	string cName, cTag;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		map<string, int> m;
		for (int j = 0; j < N; j++) {
			cin >> cName >> cTag;
			if (m.find(cTag) == m.end())
				m.insert({ cTag, 1 });
			else
				m[cTag]++;
		}
		int result = 1;
		for (auto iter : m) {
			result = result * (iter.second+1);
		}
		cout << result - 1 << "\n";
	}
}