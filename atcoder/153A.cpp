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
		
		// 标记 ABCDEF
		vector<int> arr(6, 0);
		
		arr[0] = 1;
		--N;
		for (int i = 5; i >= 0 && N > 0; --i) {
			arr[i] += N % 10;
			N /= 10;
		}
		
		// for (int i = 0; i <= 5; ++i) {
			// cout << arr[i] << ' ';
		// }
		
		cout << arr[0] << arr[0] << arr[1] << arr[2]
		<< arr[3] << arr[3] << arr[4] << arr[5] << arr[4] << '\n';
	}
	
	return 0;
}