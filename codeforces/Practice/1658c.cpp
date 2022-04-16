#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	if (count(c.begin(), c.end(), 1) != 1) {
		cout << "NO\n";
		return;
	}
	int p = find(c.begin(), c.end(), 1) - c.begin();
	rotate(c.begin(), c.begin() + p, c.end());
	for (int i = 0; i < n - 1; i++) {
		if (c[i + 1] - c[i] > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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