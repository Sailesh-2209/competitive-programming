#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r; cin >> l >> r;
	int n = r - l + 1;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int x = 0; x < 18; x++) {
		int ones = 0, zeros = 0;
		for (int i = 0; i < n; i++) {
			int num = (a[i] >> x) & 1;
			if (num) ones++;
			else zeros++;
		}
		if (ones > zeros) {
			ans += (1 << x);
		}
	}
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