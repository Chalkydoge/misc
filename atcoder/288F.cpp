#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
const ll mod = 998244353;
int t = 1;

void solve() {
	int N;
	string X;
	
	cin >> N >> X;
	
	
	vector<ll> dp(N + 1);
	ll pre = 0;
	
	// dp[0] = 1
	// dp[1] = 
	
	// dp[i] = sum_j dp[j] * X[j+1:i]
	//       = sum_j dp[j] * (10* X[j+1:i-1] + X[i:i])
	//       = 10dp[i-1] + sum_j dp[j] * X[i:i], j < i, i >= 2
 	
 	dp[0] = 1;
 	dp[1] = (X[0] - '0');
 	pre = dp[0] + dp[1]; // 2
 	
 	// dp[2] = 23| 
	for (int i = 2; i <= N; ++i) {
		dp[i] = (10 * dp[i - 1]) % mod + (pre * (ll)(X[i - 1] - '0')) % mod;
		dp[i] %= mod;
		pre = (pre + dp[i]) % mod;	 
	}
	
	cout << dp[N] % mod << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	// cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}