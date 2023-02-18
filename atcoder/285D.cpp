#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = (int)1e9 + 7;

int t = 1;
int N;

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);	
	while (t--) {
		cin >> N;
		set<string> ss;
		
		vector<string> S(N), T(N);
		map<string, int> mp;
		
		for (int i = 0; i < N; ++i) {
			cin >> S[i] >> T[i];
			ss.insert(S[i]);
			ss.insert(T[i]);	
		}
		
		int idx = 0;
		for (auto& e: ss) {
			mp[e] = idx++;
		}
		
		vector<vector<int>> g(idx, vector<int>());
		vector<int> ind(idx, 0);
		
		for (int i = 0; i < N; ++i) {
			int u = mp[S[i]], v = mp[T[i]];
			
			g[u].push_back(v);
			g[v].push_back(u);
			// cout << u << ' ' << v << '\n';	
			ind[v]++;
		}
		
		queue<int> q;
		int cnt = 0;
		
		for (int i = 0; i < idx; ++i) {
			if (ind[i] == 0) {
				q.push(i);
				++cnt;
			}
		}
		
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (auto& nxt: g[cur]) {
				--ind[nxt];
				if (ind[nxt] == 0) {
					q.push(nxt);
					++cnt;
				}
			}
		}
		
		// cout << idx << ' ' << cnt << '\n';
		
		if (cnt == idx) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
	
	return 0;
}