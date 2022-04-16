#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 9;

void solve() {
	long long n, x; cin >> n >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> ans(n + 1, -INF);
	ans[0] = 0;
	for (int l = 0; l < n; l++) {
		long long sum = 0;
		for (int r = l; r < n; r++) {
			sum += a[r];
			ans[r - l + 1] = max(ans[r - l + 1], sum);
		}
	}
	for (int k = 0; k <= n; k++) {
		long long best = 0;
		for (int i = 0; i <= n; i++) {
			best = max(best, ans[i] + (min(i, k) * x * 1LL));
		}
		cout << best << ' ';
	}
	cout << '\n';
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