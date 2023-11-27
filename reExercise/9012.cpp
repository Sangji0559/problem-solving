#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		string str;
		getline(cin, str);
		stack<char> s;
		if (i == 0) continue;
		bool flag = true;
		for (int j = 0; j < str.length(); j++) {
			char c = str[j];
			if (c == '(') s.push('(');
			else {
				if (!s.empty() && s.top() == '(') s.pop();
				else if (s.empty()) s.push(')');
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag == true && s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}