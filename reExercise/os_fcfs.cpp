#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n; // 입력받을 스레드 개수 저장
vector<pair<int, int>> v;

struct thr {
	int num; // 스레드 번호
	int start_t; // 스레드 도착 시간
	int run; // CPU 사용시간
};
queue<thr> ready_q; // 큐에 들어간 스레드


void oper_end() {
	int end = 0;
	while (!ready_q.empty()) {
		thr t = ready_q.front();
		if (end < t.start_t) // 만약 이전 스레드 완료 시간보다 도착 시간이 늦을 경우
			end = t.start_t; // 도착시간으로 변경
		end += t.run;
		v.push_back({ end - t.start_t - t.run,end }); // 출력을 위해 대기 시간과 완료 시간을 벡터에 저장
		ready_q.pop();
	}
}

int main() {

	cin >> n;
	thr tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.num >> tmp.start_t >> tmp.run;
		ready_q.push(tmp);
	} // 스레드 정보 입력

	oper_end(); // 대기 시간 및 완료 시간 연산
	cout << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout<< v[i].first << " " << v[i].second << "\n"; // 대기 시간 및 완료 시간 출력
	}
	
	return 0;
}