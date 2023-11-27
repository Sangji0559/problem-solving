#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	int csum = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),greater<int>());
	for (int i = 0; i < N; i++) {
		count = K / v[i];
		csum += count;
		K -= (count * v[i]);
		if (K == 0) break;
	}
	cout << csum;
}