#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = (int)1e9 + 7;

int t = 1;
int N;

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);	
	while (t--) {
		int a, b;
		cin >> a >> b;
				
		if (a > b) { swap(a, b); }
		
		if (b / 2 == a) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}