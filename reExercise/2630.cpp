#include<iostream>
#include<cstring>

int map[129][129];
int w_cnt = 0, b_cnt = 0;

using namespace std;

void div_conq(int x, int y, int N) {
	int tmp_cnt = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j]) tmp_cnt++;
		}
	}
	if (!tmp_cnt) w_cnt++;
	else if (tmp_cnt == N * N)b_cnt++;
	else {
		div_conq(x, y, N / 2);
		div_conq(x, y + N / 2, N / 2);
		div_conq(x + N / 2, y, N / 2);
		div_conq(x + N / 2, y + N / 2, N / 2);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	memset(map, 0, sizeof(map));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	div_conq(0, 0, n);
	cout << w_cnt << "\n";
	cout << b_cnt << "\n";
	return 0;
}