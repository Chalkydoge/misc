#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N;
	cin >> N;
	
	vector<int> a(N), b(N);
	int s = 0;
	
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		b[i] = i;
		s += i * a[i];
	}
	
	auto output = [&]() -> void {
		for (int i = 0; i < N; ++i) { cout << b[i] << ' '; }
	};
	
	// 1  xxxxx  1 这种可以
	//-1  xxxxx  -1
	if (s == 0) {
		output();
		return;
	}
	if (s > 0 && (a[0] > 0)) {
		b[0] = -s * a[0];
		output();
		return;
	}
	if (s > 0 && (a[n - 1] < 0)) {
		b[n - 1] = -(s - (n - 1) * a[n - 1]) * a[n - 1];
		output();
		return;
	}
	
	int pre = 0;
	for (int i = 0; i < N; ++i) {
		pre += a[i];
		if (pre != 0 && (pre > 0) == (a[n - 1] > 0)) {
			s = 0;
			for (int j = i + 1; j < n; ++j) {
				s += j * a[j];
			}
			for (int j = 0; j < i; ++j) {
				b[j] = j - 1e12;
				s += b[j] * a[j];
			}
			
			b[i] = -s * a[i];
			output();
			return;
		}
	}
	
	int suf = 0;
	for (int i = N - 1; i >= 0; --i) {
		suf += a[i];
		if (suf != 0 && (suf > 0) == (a[0] > 0)) {
			s = 0;
			for (int j = 1; j < i; ++j) {
				s += j * a[j];
			}
			for (int j = i + 1; j < n; ++j) {
				b[j] = 1e12 - (n - 1 - j);
				s += b[j] * a[j];
			}
			b[i] = -s * a[i];
			output();
			return;
		}
	}

	cout << "No\n";
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}
