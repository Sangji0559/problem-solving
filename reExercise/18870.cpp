#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v, s, answer;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		s.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < s.size(); i++) {
		cout << lower_bound(v.begin(), v.end(), s[i]) - v.begin() << " ";
	}
	
	return 0;
}