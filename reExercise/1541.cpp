#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;

	bool checkMinus = false;
	string num;
	int result = 0;
	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '-' || input[i] == '+' || i == input.size()) {
			if (checkMinus) {
				result -= stoi(num);
				num = "";
			}
			else {
				result += stoi(num);
				num = "";
			}
		}
		else {
			num += input[i];
		}
		if (input[i] == '-') checkMinus = true;
	}
	cout << result;

	return 0;
}