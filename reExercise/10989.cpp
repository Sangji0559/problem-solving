#include<iostream>
using namespace std;

int N[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		N[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < N[i]; j++) {
			cout << i << "\n";
		}
	}

}