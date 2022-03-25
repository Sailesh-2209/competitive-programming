#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	bool possible = true;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		bool canremove = false;
		for (int j = i + 1; j > 1; j--) {
			if (x % j) {
				canremove = true;
				break;
			}
		}
		possible &= canremove;
	}
	if (possible) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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