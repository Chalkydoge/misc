#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N;
	cin >> N;
		
	ll K;
	cin >> K;
	
	vector<ll> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }
	
	auto check = [&](ll cycle) -> bool {
		ll s = 0;
		for (auto& e: a) {
			s += min(e, cycle);
		}
		return (s >= K);
	};
	
	ll left = 0, right = K + 1;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (!check(mid)) {
			// cycle number not ok
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	ll tmp_s = 0;
	for (auto& e: a) {
		tmp_s += min(left, e);
	}
	// cout << "On cycle " << left << ", max sum is " << tmp_s << '\n';
	// 如果退出二分时 总和大于K了
	if (tmp_s > K) { --left; }
	
	// 统计执行完left轮的总数
	tmp_s = 0;
	for (auto& e: a) {
		tmp_s += min(left, e);

		if (e > left) e -= left;
		else e = 0;		
	}
	
	// 如果执行完left轮 还不够
	if (tmp_s < K) {
		// 再模拟1圈
		for (auto& e: a) {
			if (tmp_s >= K) { break; }
			if (e > 0) { --e; ++tmp_s; }
		}
	}
	
	for (auto& e: a) {
		cout << e << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
