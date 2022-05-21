#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> counts(31, 0);
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 31; x++) {
			if (a[i] >> x & 1) counts[x]++;
		}
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		int numzeros = n - counts[i];
		if (k >= numzeros) {
			int num = 1 << i;
			ans += num;
			k -= numzeros;
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