#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a % 2 == 1) { ++ans;}
		}
		cout << ans << '\n';
	}
	return 0;
}