#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* weight = new int[n];
	int* height = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> height[i];
	}
	for (int i = 0; i < n; i++) {
		int tmp = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (weight[i] < weight[j] && height[i] < height[j]) tmp++;
		}
		cout << tmp << ' ';
	}
}