#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9+7;

int t = 1;

void solve() {
	int sx, sy, tx, ty;
	
	int a, b, c, d;
	
	cin >> sx >> sy >> tx >> ty;
	
	cin >> a >> b >> c >> d;
	
	// sx, sy 通过一个点 u, v进行镜像翻转
	// 翻转点计算 2u - sx, 2u - sy,
	// 奇数-奇数, 偶数-偶数 所以如果起点/终点奇偶不匹配 => 直接寄	
	if ((sx - tx) % 2 != 0 || (sy - ty) % 2 != 0) {
		cout << "No\n";
		return;
	}
	
	vector<pair<int,int> > ans;

	auto move = [&](const auto& x, const auto& y) -> void {
		ans.emplace_back(x, y);
		sx = 2 * x - sx;
		sy = 2 * y - sy;
	};
	
	// a,b 坐标重合; sx,tx不同=>尝试flip
	if (a == b && sx != tx) {
		move(a, c);
	}
	// c,d 坐标重合; sy,ty不同=> 尝试flip
	if (c == d && sy != ty) {
		move(a, c);
	}
	
	if (a == b) {
		// flip也不行 寄!
		if (sx != tx) {
			cout << "No\n";
			return;
		}
	}
	else {
		// sx在tx的左边, 借助左下角
		while (sx < tx) {
			// sx, sx+2, ... 向前走
			move(a, c);
			move(a + 1, c);
		}
		while (sx > tx) {
			// sx, sx-2, ... 向后退
			move(a + 1, c);
			move(a, c);
		}
	}

	if (c == d) {
		// flip也不行 寄!
		if (sy != ty) {
			cout << "No\n";
			return;
		}
	}
	else {
		while (sy < ty) {
			move(a, c);
			move(a, c + 1);
		}
		while (sy > ty) {
			move(a, c + 1);
			move(a, c);
		}
	}
	
	// 次数 <= 2 * (1e5 + 1e5) < 1e6 (每次前进2/后退2)
	if (sx == tx && sy == ty) {
		cout << "Yes\n";
		for (auto& pr: ans) {
			cout << pr.first << ' ' << pr.second << '\n';
		}
	} else {
		cout << "No\n";
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