#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum=0;
	vector<int> v;

	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			sum += v[i];
			continue;
		}
		v[i] = v[i] + v[i - 1];
		sum += v[i];
	}
	cout << sum;
}