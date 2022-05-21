#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1e9 + 5;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cur = 0;
			for (int k = 0; k < m; k++) {
				int diff = a[i][k] - a[j][k];
				cur += abs(diff);
			}
			ans = min(ans, cur);
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