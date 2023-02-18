#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int N, K;
vector<pair<int,int> > q;
priority_queue<int> pq;

int main() {
	cin >> N >> K;
	
	// 哨兵节点 替换为0
	q.emplace_back(1, 0);
	
	for (int i = 1; i <= N; ++i) {
		int t, y;
		cin >> t >> y;
		q.emplace_back(t, y);
	}
	
	ll s = 0;
	ll ans = -inf;

	for (int i = N; i >= 0; --i) {
		int y = q[i].second;
		if (q[i].first != 2) {
			/* 后面一段的2操作累加和 + 当前替换的y */
			ans = max(ans, y + s);
			// 无法跳过操作1了
			if (K == 0) { break; }
			--K; // 跳过操作1
		} else if (y >= 0) {
			s += y;
		} else {
			// 负数存堆
			pq.push(y);
		}
		// 堆里全部跳过需要的次数大于k => 少跳, 选最大的负数
		if ((int)pq.size() > K) {
			s += pq.top();
			pq.pop();
		}
	}
	
	cout << ans << endl;
	
	return 0;
}