#include<iostream>
#include<string>

string e_list;

using namespace std;

void encode_list(string s) {
	for (int i = 0; i < s.size(); i++) {
		e_list[i]=hex(s[i + 128 % s.size()]+20)
	}
}

int main() {
	string s;
	cout << "문자를 입력하세요: " << "\n";
	cin >> s;
	encode_list(s);
	cout << e_list;
	return 0;
}