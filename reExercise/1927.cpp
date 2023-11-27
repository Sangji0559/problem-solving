#include<iostream>
#include<queue>
 
using namespace std;

int cnt;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (pq.empty())
				cout << "0" << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}

	return 0;
}