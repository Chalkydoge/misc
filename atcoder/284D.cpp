#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll N;

int mx = (int)3e6 + 10;

vector<int> is_prime(mx, 1);
vector<ll> primes;

void init() {
	for (int i = 2; i <= mx; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
			if ((ll)i * i <= mx) {
				for (int j = i * i; j <= mx; j += i) {
					is_prime[j] = 0;
				}	
			}
		}
	}
}

int main() {
	
	init();
	
	cin >> t;
	
	while (t--) {
		cin >> N;
		
		// p^2 q p很大 -> q很小
		// p很小 -> q很大
		// p=q, p,q大概都是 3e6
		
		bool fl = false;
		
		// 枚举q
		for (auto& q: primes) {
			if (N % q == 0) {
				ll ps = N / q;
				ll p = (ll)(sqrt(ps));
				if (p * p == ps) {
					cout << p << ' ' << q << '\n';
					fl = true;
					break;
				}
			}
		}
		
		if (fl) {
			continue;
		}
		
		// 枚举p
		for (auto& p: primes) {
			ll ps = p * p;
			if (N % ps == 0) {
				cout << p << ' ' << N / ps << '\n';
				fl = true;
				break;
			}
		}
		
	}
	return 0;
}