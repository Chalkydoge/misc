#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string t;

const ll mod = 1E9 + 7;
const ll prime = 129;

ll f[1000005], g[1000005], h[1000005];

ll qpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) { res *= x; res %= mod; }
		y >>= 1;
		x *= x; x %= mod;
	}
	return res;
}

// t[0] t[1] t[2] ... t[n - 1]
// a0 + a1 x + a2 x^2 + ... + a_(n-1) x^(n-1)
int main() {
	cin >> n >> t;
	
	ll h1 = 0;
	
	// 后半段 反向hash 结果缓存到g
	for (int i = 2 * n; i > n; --i) {
		h1 += (t[i - 1] - 'a') * qpow(prime, 2 * n - i);
		h1 %= mod;
		g[i - n] = h1;
	}
	
	h1 = 0;
	
	// 前半段 反向hash 结果缓存到f
	for (int i = n; i >= 1; --i) {
		h1 = h1 * prime + (t[i - 1] - 'a');
		h1 %= mod;
		f[i] = h1;
	}
	
	h1 = 0;
	// 前半段 正向hash 结果缓存到h
	for (int i = 1; i <= n; ++i) {
		h1 += (t[i - 1] - 'a') * qpow(prime, i - 1);
		h1 %= mod;
		h[i] = h1;
	}
	
	h1 = 0;
	for (int i = n; i <= 2 * n; ++i) {
		// t[n: i] 
		if ((h1 == h[i - n]) && (f[i - n + 1] == g[i - n + 1] || i == 2 * n)) {
			for (int j = i; j > i - n; --j) {
				cout << t[j - 1];
			}
			cout << '\n' << i - n;
			return 0;
		}
		
		h1 = h1 * prime + (t[i + 1] - 'a');
		h1 %= mod;
	}
	// s知道
	// s的反也知道
	
	// 挖掉两个 剩下的相对位置不变
	// |s/2|个可能性, 如何快速判断?
	
	// 预处理hash(r(s))
	// 根据移除的位置 i 和 N - i 快速修改hash计算
	
	// h(s) = ^i + ^(N - i)
	// ^i前面的不变
	// [i + 1, N - i - 1]这些变大了1次
	// [N - i + 1, N - 1]变大了两次
	
	// 预处理一个前缀和搞定
	// 然后看hash的结果是否和题目中给的一样
	cout << -1 << '\n';
	return 0;
}