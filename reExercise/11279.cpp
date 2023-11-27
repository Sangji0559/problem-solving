#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}
}