#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N,sum=0;
	cin >> N;
	stack<int> st;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp != 0) {
			st.push(tmp);
			sum += tmp;
		}
		else {
			sum -= st.top();
			st.pop();
		}
	}
	cout << sum;
}