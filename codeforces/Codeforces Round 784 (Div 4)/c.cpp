#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (a[1] % 2 == 0) { // even numbers at odd indices
		for (int i = 1; i <= n; i += 2) {
			if (a[i] % 2 == 1) {
				cout << "NO\n";
				return;
			}
		}
	} else { // odd numbers at odd indices
		for (int i = 1; i <= n; i += 2) {
			if (a[i] % 2 == 0) {
				cout << "NO\n";
				return;
			}
		}
	}
	if (a[2] % 2 == 0) { // even numbers at even indices
		for (int i = 2; i <= n; i += 2) {
			if (a[i] % 2 == 1) {
				cout << "NO\n";
				return;
			}
		}
	} else { // odd numbers at even indices
		for (int i = 2; i <= n; i += 2) {
			if (a[i] % 2 == 0) {
				cout << "NO\n";
				return;
			}
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