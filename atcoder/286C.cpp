#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int t = 1;

void solve() {
	int n;
	cin >> n;
	
	ll a, b;
	cin >> a >> b;
	
	string s;
	cin >> s;
	
	ll ans = inf;
	
	for (int i = 0; i < n; ++i) {
		// use A for i times
		
		vector<char> v;
		ll tmp = 0;
		
		for (int j = i; j < n; ++j) { v.push_back(s[j]); }
		for (int j = 0; j < i; ++j) { v.push_back(s[j]); }
		tmp += (ll)i * a;
		
		int i1 = 0, j1 = v.size() - 1;
		ll cnt = 0;
		while (i1 < j1) {
			if (v[i1] != v[j1]) {
				++cnt;
			}
			++i1;
			--j1;
		}
		tmp += cnt * b;
		
		ans = min(ans, tmp);
	}
	
	cout << ans << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}