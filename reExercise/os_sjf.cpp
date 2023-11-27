/*
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef struct thr {
	int num;
	int set_time;
	int run_time;
}Thr;

int n;
int present_time = 0;
vector<pair<int, int>> end_time, wait_time;
deque<Thr> ready_q;

bool compare_time(Thr a, Thr b){
	if (a.run_time > b.run_time) return true;
	else if (a.run_time == b.run_time && a.num > b.num) return true;
	return false;
}

bool compare_num(pair<int,int> a, pair<int,int> b){
	if (a.first < b.first) return true;
	return false;
}

void oper_end() {
	int end = 0;
	while (!ready_q.empty()) {
		Thr t = ready_q.front();
		if (end < t.set_time)
			end = t.set_time;
		end += t.run_time;
		end_time.push_back({ t.num,end });
		wait_time.push_back({ t.num,end - t.set_time - t.run_time });
		ready_q.pop_front();
		sort(ready_q.begin(), ready_q.end(), compare_time);
	}
}

int main() {
	cin >> n;
	Thr tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.num >> tmp.set_time >> tmp.run_time;
		ready_q.push_back(tmp);
	}

	oper_end(); // 대기 시간 및 완료 시간 연산
	cout << "\n";

	sort(end_time.begin(), end_time.end(), compare_num);
	sort(wait_time.begin(), wait_time.end(), compare_num);

	for (int i = 0; i < n; i++) {
		cout << wait_time[i].second << " " << end_time[i].second << "\n";
	}

	return 0;
}
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef struct thr {
	int num;
	int set_time;
	int run_time;
}Thr;

struct compare_time {
	bool operator()(Thr a, Thr b) const{
		if (a.run_time > b.run_time) return true;
		else if (a.run_time == b.run_time && a.num > b.num) return true;
		return false;
	}
};

bool compare_settime(Thr a, Thr b){
	if (a.set_time > b.set_time) return true;
	return false;
}

int n;
int present_time;
priority_queue <Thr, vector<Thr>, compare_time> ready_q;
deque<Thr> v;

int main() {
	cin >> n;
	Thr tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.num >> tmp.set_time >> tmp.run_time;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), compare_settime);
	while (!v.empty()) {
		if (present_time == v.front().set_time) {
			ready_q.push(v.front());
			v.pop_front();
		}
		present_time++;
	}

	return 0;
}