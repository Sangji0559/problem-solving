#include<iostream>
#include<cstring>

using namespace std;
bool checkNum[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if (temp == "add") {
			cin >> num;
			checkNum[num] = true;
		}
		else if (temp == "remove") {
			cin >> num;
			checkNum[num] = false;
		}
		else if (temp == "check") {
			cin >> num;
			checkNum[num] ? (puts("1")) :(puts("0"));
		}
		else if (temp == "toggle") {
			cin >> num;
			checkNum[num] ? (checkNum[num]=false) : (checkNum[num] = true);
		}
		else if (temp == "all") {
			memset(checkNum, true, sizeof(checkNum));
		}
		else if (temp == "empty") {
			memset(checkNum, false, sizeof(checkNum));
		}
		
	}

}