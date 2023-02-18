#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		if(s[i] == '0') {
			cout << 1;
		} else {
			cout << 0;
		}
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