#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string CHESS[50];

int check(int n, int m) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (CHESS[i][j] != BW[i - n][j - m]) cnt1++;
		}
	}
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (CHESS[i][j] != WB[i - n][j - m]) cnt2++;
		}
	}
	
	return min(cnt1, cnt2);
}

int main() {
	int N, M;
	int mini = 15000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			cin >> CHESS[i];
	}
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			if (mini > check(i, j)) mini = check(i, j);
		}
	}

	cout << mini;
}