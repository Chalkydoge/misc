#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N,K;
	cin >> N >> K;
	
	vector<string> s(K);
	
	for (int i = 0; i < K; ++i) {
		cin >> s[i];
	}
	for (int i = K; i < N; ++i) { string tmp; cin >> tmp;}
	
	sort(s.begin(), s.end());
	
	for (auto& ss: s) {
		cout << ss << '\n';
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
