#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int N, K;
	cin >> N >> K;
	
	/*
	 给定 a(N)
	 补上a[0]和a[n+1] = 0
	 
	 得到一个N+2的数组
	 a[0], a[1], ..., a[n], a[n+1]
	 
	 差分x[0] = a[1] - a[0], x[1] = a[2] - a[1], ..., x[]
	
	 得到一个x(N + 1)的差分数组
	 
	 那么原始数组[l, l+K]上操作的意义 等价于
	 !!注意差分这里下标右移了1单位
	 x[l - 1] += c (a[l] - a[l - 1])
	 x[l + K - 1] -= c (也就是差分) (a[l + K] - a[l + K - 1])
	 
	 那么可以发现会同时影响l - 1 和 l - 1 + K两个位置上的元素, 一个+c 一个-c
	 
	 由于经过一系列操作后 a变成了0
	 
	 于是对应差分肯定也是全0 所以 x[0] = x[1] = ... = x[n + 1] = 0
	 
	 那么既然差分会变成0, 而我们的操作会同时影响l - 1, l - 1 + K两个位置的差分大小
	 
	 l - 1, l - 1 + K, l - 1 + 2K, ...,
	 
	 r + nK 发现关于K的余数有关系!
 	 
	 我们可以发现它们的差分和是不变的!
	 
	 r = l - 1
	 r, r + K, r + 2K, ...,
	 
	 [L, R]区间内
	 
	 L >= aK+r  ..., R <= bK+r
	 
	 余数等于r的这一系列差分和都是可以预先求出来的!
	 
	 于是我们可以O(K)的判断这些和是否可能为0 => O(QK)的判断询问
	 
	*/
	
	
	// 原数组
	vector<ll> a(N);
	
	
	// 差分的前缀和S
	vector<ll> s(N);
	
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		s[i] = a[i];
		if (i >= K) {
			s[i] += s[i - K];
		} 
	}
	
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int L, R;
		cin >> L >> R;
		--L; --R;
		
		vector<int> b(K);
		for (int i = R; (R - i + 1) <= K; --i) {
			b[i % K] += s[i]; // s是隔K的前缀和
		}
		for (int i = L - 1; i >= 0 && (L - i) <= K; --i) {
			b[i % K] -= s[i]; // 前缀和差分 获得差值
		}
		
		// 差分后得到的和 在当前区间内 关于每个余数都相等 说明可以完成
		if (b == vector<int>(K, b[0])) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
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
