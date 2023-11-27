#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 0, cnt = 0;
	while (cnt != n) {
		result++;
		int tmp = result;

		while (tmp != 0) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			else tmp /= 10;
		}
	}
	cout << result;
}