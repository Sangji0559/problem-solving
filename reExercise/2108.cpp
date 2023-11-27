#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
int N;

int main() {
	cin >> N;
	int tmp, mean=0, mode = 0, min, max = 0;
	bool isSecond = false;
	vector<int> v(N);
	vector<int> v2(8001, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		mean+=v[i];
		tmp = (v[i] <= 0) ? abs(v[i]) : v[i] + 4000;
		v2[tmp]++;
		if (v2[tmp] > max) {
			max = v2[tmp];
		}
	}
	sort(v.begin(), v.end());
	for (int i = -4000; i < 4001; i++) {
		tmp = i <= 0 ? abs(i) : i + 4000;
		if (v2[tmp] == max) {
			mode = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}
	tmp = round(mean / (double)N);
	cout << tmp << "\n";
	cout << v[round(N / 2)] << "\n";
	cout << mode << "\n";
	min = v[0];
	max = v[v.size() - 1];
	cout << max - min << "\n";
}