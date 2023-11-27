#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n; // �Է¹��� ������ ���� ����
vector<pair<int, int>> v;

struct thr {
	int num; // ������ ��ȣ
	int start_t; // ������ ���� �ð�
	int run; // CPU ���ð�
};
queue<thr> ready_q; // ť�� �� ������


void oper_end() {
	int end = 0;
	while (!ready_q.empty()) {
		thr t = ready_q.front();
		if (end < t.start_t) // ���� ���� ������ �Ϸ� �ð����� ���� �ð��� ���� ���
			end = t.start_t; // �����ð����� ����
		end += t.run;
		v.push_back({ end - t.start_t - t.run,end }); // ����� ���� ��� �ð��� �Ϸ� �ð��� ���Ϳ� ����
		ready_q.pop();
	}
}

int main() {

	cin >> n;
	thr tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.num >> tmp.start_t >> tmp.run;
		ready_q.push(tmp);
	} // ������ ���� �Է�

	oper_end(); // ��� �ð� �� �Ϸ� �ð� ����
	cout << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout<< v[i].first << " " << v[i].second << "\n"; // ��� �ð� �� �Ϸ� �ð� ���
	}
	
	return 0;
}