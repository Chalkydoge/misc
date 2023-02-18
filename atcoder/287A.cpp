#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n;
	cin >> n;
	
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s[0] == 'F') { ++a; }
		else { ++b; }
	}
	
	if (a > b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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
