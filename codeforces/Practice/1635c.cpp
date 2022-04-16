#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (a[n - 1] < a[n - 2]) {
		cout << "-1\n";
		return;
	}
	if (a[n - 1] >= 0) {
		cout << (n - 2) << '\n';
		for (int i = 0; i < n - 2; i++) {
			cout << (i + 1) << ' ' << (n - 1) << ' ' << n << '\n';
		}
	} else {
		if (is_sorted(a.begin(), a.end())) {
			cout << "0\n";
		} else {
			cout << "-1\n";
		}
	}
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