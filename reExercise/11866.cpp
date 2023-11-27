#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<int> select(int k, queue<int>& q) {
	vector<int> result; // 결과 값 저장할 vector
	int cnt = 0;
	int x;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		cnt++;
		if (cnt == k) {
			result.push_back(x);
			cnt = 0;
			continue;
		}
		q.push(x);
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	vector<int> result = select(k, q);

	cout << "<";
	for (int i = 0; i < result.size() - 1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[result.size()-1] << ">";
}