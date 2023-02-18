#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> s(N);
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
	}
	for (int i = N - 1; i >= 0; --i) {
		cout << s[i] << '\n';
	}
	return 0;
}