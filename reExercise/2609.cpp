#include<iostream>
#include<algorithm>

using namespace std;

int GCD(int n, int m) {
	if (n % m == 0)
		return m;
	else
		return GCD(m, n % m);
}

int main() {
	int n, m;
	cin >> n >> m;
	int gcd = 0, lcm = 0;
	if (n >= m) {
		gcd=GCD(n, m);
	}
	else {
		gcd = GCD(m, n);
	}
	lcm = n * m / gcd;
	cout << gcd << endl;
	cout << lcm << endl;
}