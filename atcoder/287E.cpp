#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

struct Node {
	Node *son[26]{};
	int score = 0;
};



void solve() {
	int n;
	cin >> n;
	
	vector<string> w(n);
	
	Node* root = new Node();
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		auto cur = root;
		for (char c: w[i]) {
			int x = c - 'a';
			if (!cur->son[x]) { cur->son[x] = new Node(); }
			cur = cur->son[x];
			++cur->score; // 前缀出现次数
		}	
	}
	
	
	for (int i = 0; i < n; ++i) {
		// remove
		auto cur = root;
		for (char c: w[i]) {
			int x = c - 'a';
			cur = cur->son[x];
			--cur->score; // 前缀出现次数
		}	
		
		int l = 0;
		cur = root;
		for (char c: w[i]) {
			int x = c - 'a';
			cur = cur->son[x];
			if (cur->score > 0) {
				++l;
			} else { break; }
		}
		cout << l << '\n';
		
		// add back
		cur = root;
		for (char c: w[i]) {
			int x = c - 'a';
			cur = cur->son[x];
			++cur->score; // 前缀出现次数
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
