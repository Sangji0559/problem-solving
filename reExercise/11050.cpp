#include<iostream>

using namespace std;

int bino_coef(int n, int k) {
	if (k == 0 || n == k) {
		return 1;
	}
	return bino_coef(n - 1, k) + bino_coef(n - 1, k - 1);

}

int main() {
	int N, K;
	cin >> N >> K;

	cout << bino_coef(N, K);
}