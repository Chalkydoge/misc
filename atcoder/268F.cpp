#include <bits/stdc++.h>
#define ll long long
#define inf LLONG_MAX

using namespace std;

int N;

int main() {
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		ll xa = 0, xb = 0;
		ll ya = 0, yb = 0;
		for (auto& ch: a) {
			if (ch == 'X') { ++xa; }
			else { ya += (ch - '0'); }
		}
		for (auto& ch: b) {
			if (ch == 'X') { ++xb; }
			else { yb += (ch - '0'); }
		}
		return xa * yb > xb * ya;
	});
	
	
	ll ans = 0;
	ll x = 0;
	for (auto& s: v) {
		for (auto&ch : s) {
			if (ch == 'X') {
				++x;
			} else {
				ll y = (ch - '0');
				ans += x * y;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}