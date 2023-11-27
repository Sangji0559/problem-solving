#include<iostream>

using namespace std;

long long dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int input;
	int first, second;
	long long tmp=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		tmp = tmp + input;
		dp[i] = tmp;
	}
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		cout << dp[second - 1] - dp[first - 2] <<"\n";
	}
}