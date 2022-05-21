#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long ans = 1e18;
	for (int p = 0; p < n; p++) {
		long long prev = 0, ops = 0;
		for (int i = p - 1; i >= 0; i--) {
			prev += a[i] - prev % a[i];
			ops += prev / a[i];
		}
		prev = 0;
		for (int i = p + 1; i < n; i++) {
			prev += a[i] - prev % a[i];
			ops += prev / a[i];
		}
		ans = min(ans, ops);
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
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}