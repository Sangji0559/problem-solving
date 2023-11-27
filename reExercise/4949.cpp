#include<iostream>
#include<stack>
#include<string>


using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") {
			break;
		}
		stack<char> s;
		bool flag = true;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (c == '(') s.push('(');
			else if (c == '[') s.push('[');
			else if (c == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (c == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag == true && s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}