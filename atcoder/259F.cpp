#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, ll> E;

int N;

int d[300005];

// dp[v][0]: v节点子树 度数 < dv的最大和
// dp[v][1]: v节点子树 度数 <= dv的最大和
ll dp[300005][2];

vector<E> g[300005];

const ll inf = 1e18;

void dfs(int u, int p) {
	vector<ll> vec;
	
	for (auto& e: g[u]) {
		int v = e.first;
		ll w = e.second;
		
		if (v == p) { continue; }
		
		dfs(v, u);
		
		// cost-delta = (choose 1) - (choose 2)
		vec.push_back(dp[v][0] + w - dp[v][1]);
		
		dp[u][0] += dp[v][1];
		dp[u][1] += dp[v][1];	
	}
	
	sort(vec.rbegin(), vec.rend());
	
	for (int i = 0; i < (int)vec.size(); ++i) {
		if (vec[i] <= 0) { break; }
		if (i < d[u] - 1) {
			dp[u][0] += vec[i];
		}
		if (i < d[u]) {
			dp[u][1] += vec[i];
		}
	}
	
	if (d[u] == 0) { 
		// 当d[u] = 0是 u为子树根节点的度数 < du的情况不可能存在
		dp[u][0] = -inf;
	}
}

int main() {
	cin >> N;	
	for (int i = 1; i <= N; ++i) {
		cin >> d[i];
	}
	for (int i = 2; i <= N; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	dfs(1, -1);
	cout << dp[1][1] << endl;

	return 0;
}