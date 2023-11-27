#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<pair<int, int>> vec(cnt);
	for (int i = 0; i < cnt; i++)
		cin >> vec[i].first >> vec[i].second;

	sort(vec.begin(), vec.end());

	for (int i = 0; i < cnt; i++)
		cout << vec[i].first << " " << vec[i].second << "\n";

}