#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N;
	cin >> N;
	
	map<ll, int> cnt;
	cnt[0] = 1;
	
	ll s = 0;
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		ll v;
		cin >> v;
		
		if (i % 2 == 0) s += v;
		else s -= v;
		
		ans += cnt[s];
		++cnt[s];
	}
	
	cout << ans << '\n';
	
	// 连续两个数字 +1 / -1
	// 总是在一个奇数位上+1, 一个偶数维上+1
	// 子数组可能被操作变成0 => S0 = S1
	
	// 11 3 3 13 2
	// 11 + 3 + 2
	// 3 + 13 == 11 + 3 + 2 所以是可以的
	// 交错和相等 == 交错和的差为0 == 这样表示 +1 -1 +1 -1 ...的子数组和为0, 求数量
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
