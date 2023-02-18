#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	string s, t;
	cin >> s >> t;
	
	int n = (int)s.size();
	int m = (int)t.size();
	
	// 前缀匹配长度 s1, 后缀匹配长度s2
	// 后面取个数 大于s2 或者前面取个数 大于s1 一定是false
	int s1 = 0, s2 = 0;
	
	for (int i = 0; i < m; ++i) {
		if (s[i] == t[i] || s[i] == '?' || t[i] == '?') {
			++s1;
		} else { break; }
	}
	for (int i = m - 1; i >= 0; --i) {
		if (s[n - 1 - (m - 1 - i)] == t[i] || s[n - 1 - (m - 1 - i)] == '?' || t[i] == '?') {
			++s2;
		} else { break; }
	}
	
	// cout << s1 << ' ' << s2  << '\n';
	for (int k = 0; k <= m; ++k) {
		if (s1 >= k && s2 >= m - k) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
