#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> counts(31, 0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < 31; j++) {
			if (x >> j & 1) {
				counts[j]++;
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		bool ok = true;
		for (int i = 0; i < 31; i++) {
			if (counts[i] % k) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << k << ' ';
		}
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