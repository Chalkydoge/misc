#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = (int)1e9 + 7;

int t = 1;
int N;

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);	
	while (t--) {
		string S;
		cin >> N >> S;
		
		for (int i = 1; i <= N - 1; ++i) {
			int ans = 0;
			
			int left = 0, right = N - i + 1;
			while (left < right) {
				int mid = (left + right) / 2;
				
				bool fl = true;
				for (int k = 1; k <= mid; ++k) {
					if (S[k - 1] == S[k + i - 1]) { fl = false; break; }
				}
				
				if (fl) {
					ans = mid;
					left = mid + 1;
				} else {
					right = mid;
				}
			}
			
			cout << ans << '\n';
		}
	}
	
	return 0;
}