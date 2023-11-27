#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int temp;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> temp;
		cout << binary_search(v.begin(), v.end(), temp) << "\n";
	}
}