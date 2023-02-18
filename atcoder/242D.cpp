#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int q;

int t = 1;

string S;

char mp[3][2] = {{'B', 'C'}, {'C', 'A'}, {'A', 'B'} };

char dfs(ll idx, ll k) {
	vector<ll> path;
	
	while (1) {
		path.push_back(k);
		k /= 2;
		--idx;
		if (idx < 0 || k <= 0) { break; }
	}
	
	// idx -  1 = 'A', kth -> idx, 2k [B], 2k+1 [C]
	// trace back
	
	// p[0] = i -> S[i]
	// p[1] = x -> S[]	
	char nxt_ch = S[path.back()];
	if (idx > 0) {
		nxt_ch = mp[nxt_ch - 'A'][path.back() % 2];
	}

	for (int i = (int)path.size() - 2; i >= 0; --i) {
		nxt_ch = mp[nxt_ch - 'A'][path[i] % 2];
	}
	return nxt_ch;
} 


void solve() {
	cin >> S;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll idx, k;
		cin >> idx >> k;
		--k;
		cout << dfs(idx, k) << '\n';
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