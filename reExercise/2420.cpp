#include<iostream>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long result = (long long)(n - m);
	if (result < 0) {
		result = result * -1;
	}
	cout << result;
}