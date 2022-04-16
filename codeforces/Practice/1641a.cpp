#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	long long x;
	cin >> n >> x;
	vector<long long> a(n);
	map<long long, long long> omap;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		omap[a[i]]++;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (omap[a[i]] == 0) continue;
		omap[a[i]]--;
		if (omap[(a[i] * x)] > 0) {
			omap[(a[i] * x)]--;
		} else {
			ans++;
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