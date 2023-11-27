#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int resDp[50001];

void makeDp(int num) {
	for (int i = 1; i * i <= num; i++) {
		if (resDp[num] == 0) {
			resDp[num] = resDp[i * i] + resDp[num - i * i];
		}
		else {
			resDp[num] = min(resDp[num], resDp[i * i] + resDp[num - i * i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int size = sqrt(n);
	for (int i = 1; i * i <= n; i++) {
		resDp[i * i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (resDp[i] != 0) continue;
		makeDp(i);
	}
	cout << resDp[n];
}