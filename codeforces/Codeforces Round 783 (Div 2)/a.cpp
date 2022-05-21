#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	if ((n == 1 && m > 2) || (m == 1 && n > 2)) {
		cout << "-1\n";
		return;
	}
	if (n == 1 && m == 1) {
		cout << "0\n";
		return;
	}
	int val = max(m, n);
	int ans = ((val - 2) * 2) + 2;
	if (abs(m - n) % 2 == 1) ans--;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}