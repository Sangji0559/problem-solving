#include<iostream>

using namespace std;

void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1)
		cout << " ";
	else if (n / 3 == 0)
		cout << "*";
	else
		star(i, j, n / 3);

}

int main() {
	ios_base::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	for(int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			star(i, j, cnt);
		}
		cout << "\n";
	}

	return 0;
}