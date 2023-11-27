#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n,tmp=1;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!(q.empty())) {
		q.pop();
		if (q.empty())
			break;
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << tmp;
}