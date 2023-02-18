#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int n;
	string s;
	
	cin >> n >> s;
	
	
	// XXXX A => ABBBA
	// B XXXX => BAAAB
	if ((s[0] == 'A' && s[n - 1] == 'B') || s == "BA") {
		cout << "No\n";
	} else {
		cout << "Yes\n";
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