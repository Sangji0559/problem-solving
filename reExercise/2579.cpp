#include<iostream>

using namespace std;

int retMax(int a, int b) {
	if (a > b)return a;
	else return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	int arr[301][3];
	cin >> arr[1][0];
	arr[1][1] = arr[1][2] = arr[1][0];

	for (int i = 2; i < cnt+1; i++) {
		cin >> arr[i][0];
		arr[i][1] = arr[i - 1][2] + arr[i][0];
		arr[i][2] = retMax(arr[i - 2][1], arr[i - 2][2]) + arr[i][0];
	}

	cout << retMax(arr[cnt][1], arr[cnt][2]);
}