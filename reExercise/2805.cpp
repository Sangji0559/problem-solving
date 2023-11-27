#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
int n;
int len;
vector<int> v;

bool isPossible(int l) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] - l < 0) continue;
		cnt += v[i] - l;
	}
	if (cnt >= len) return true;
	else return false;
}

void solve() {
	sort(v.begin(), v.end());
	unsigned int left = 0, right = v[v.size() - 1];
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	solve();
}
*/


int main() {

	int n, len;
	cin >> n >> len;
	long long* tree = new long long[n];

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	long long high = 1000000000;
	long long low = 0;
	long long mid;
	long long cut_tree;
	long long ans = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		cut_tree = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				cut_tree = cut_tree + (tree[i] - mid);
			}
		}
		if (cut_tree == len) {
			ans = mid;
			break;
		}
		else if (cut_tree > len) {
			if (ans < mid) {
				ans = mid;
			}
			low = mid + 1;
		}
		else if (cut_tree < len) {
			high = mid - 1;
		}
	}
	cout << ans;
	delete[] tree;
}