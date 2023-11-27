#include<iostream>

using namespace std;

int height[257];

int main() {

	long long n, m, b;
	int a;
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			height[a]++;
		}
	}

	long long result = 99999999;
	long long sum, sub, time;
	int res2 = 0;

	for (int i = 0; i < 257; i++) {
		sum = 0;
		sub = 0;
		for (int j = 0; j < i; j++) {
			sum += (i - j) * height[j];
		}
		for (int k = i + 1; k < 257; k++) {
			sub += (k - i) * height[k];
		}
		if (sum <= sub + b) {
			time = sum + sub * 2;
			if (result >= time) {
				result = time;
				res2 = i;
			}
		}
	}
	cout << result << " " << res2;

}