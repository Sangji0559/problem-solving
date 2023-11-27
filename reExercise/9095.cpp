#include<iostream>

using namespace std;

int dp[11];

int Tadd(int k) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= k; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	return dp[k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout << Tadd(temp) << "\n";
	}


}