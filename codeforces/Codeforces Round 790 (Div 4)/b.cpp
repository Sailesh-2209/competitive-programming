#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int minval = 1e9 + 5;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		minval = min(minval, a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] - minval;
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