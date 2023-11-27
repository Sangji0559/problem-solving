#include<iostream>

using namespace std;
long long dp[101];

long long fado(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (dp[n] != 0) return dp[n];
	dp[n] = fado(n - 2) + fado(n - 3);
	return dp[n];
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << fado(num)<<"\n";
	}
}