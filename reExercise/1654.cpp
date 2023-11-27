#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int N, K;
vector<int> lan;

bool isPossible(int len) {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cnt += lan[i] / len;
	}
	if (cnt >= K) {
		return true;
	}
	else
		return false;
}


int main() {

	cin >> N >> K;
	lan.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> lan[i];
	}

    sort(lan.begin(), lan.end());

    unsigned int left = 1, right = lan[lan.size() - 1];
    unsigned int result = 0;

    while (left <= right) {
        unsigned int mid = (left + right) / 2;

        if (isPossible(mid)) {
            result = max(result, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << result;

}