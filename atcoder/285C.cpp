#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = (int)1e9 + 7;

int t = 1;
int N;

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);	
	while (t--) {
		string S;
		cin >> S;
		ll res = 0;
		for (int i = 0; i < (int)S.size(); ++i) {
			res = res * 26 + (ll)(S[i] - 'A' + 1);
		}
		cout << res << '\n';
	}
	
	return 0;
}