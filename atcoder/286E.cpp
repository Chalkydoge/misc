#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;
int N;

string s[305];

vector<int> g[305];

// floyd
int dis[305][305];

// max value
ll ans[305][305];

ll arr[305];

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
	}
	
	// 建图
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (s[i][j] == 'Y') {
				g[i].push_back(j);
				dis[i][j] = 1;
				ans[i][j] = arr[i] + arr[j];
			}
		}
	}
	
	for (int k = 0; k < N; k++) {
  		for (int x = 0; x < N; x++) {
		    for (int y = 0; y < N; y++) {
		      	if (dis[x][k] + dis[k][y] < dis[x][y]) {
			      	dis[x][y] = dis[x][k] + dis[k][y];
					ans[x][y] = ans[x][k] + ans[k][y] - arr[k];	      		
		      	} else if (dis[x][k] + dis[k][y] == dis[x][y]) {
		      		ans[x][y] = max(ans[x][y], ans[x][k] + ans[k][y] - arr[k]);	    
		      	}
		    }
  		}	
	}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if (dis[u][v] == 0x3f3f3f3f) {
			cout << "Impossible" << '\n';
			continue;
		} else {
			cout << dis[u][v] << ' ' << ans[u][v] << '\n';
		}
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