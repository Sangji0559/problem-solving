#include<iostream>

using namespace std;
int check[202];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		check[temp+101]++;
	}
	int t;
	cin >> t;
	cout << check[t + 101];
	return 0;
}