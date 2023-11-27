#include<iostream>

using namespace std;

int cnt, first, second;
int check, divisior;

int main() {

	cin >> cnt;
	for (int k = 0; k < cnt; k++) {
		cin >> first >> second;
		divisior = 0;
		for (int i = first; i <= second; i++) {
			check = 0;
			for (int j = 1; j * j <= i; j++) {
				if (i % j == 0) {
					if (j * j == i) check++;
					if (j * j < i) check += 2;
				}
			}
			if (i % check == 0) divisior++;
		}
		cout << divisior << "\n";
	}
	return 0;
}