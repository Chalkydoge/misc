#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	string ans;
	for (int i = 0; i < n; ) {
		if (i < n - 1 && s[i] == 'n' && s[i + 1] == 'a') {
			ans += "nya";
			i += 2;
		} else {
			ans += s[i];
			i += 1;
		}
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