#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long ans = 0;
	for (int len = 1; len <= n; len++) { // subsegment length
		for (int start = 0; start + len <= n; start++) {
			int cnt = 0;
			for (int i = start; i < start + len; i++)
				if (a[i] == 0) cnt++;
			ans += len + cnt;
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