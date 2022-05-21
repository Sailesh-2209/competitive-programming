#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) 
		cin >> grid[i];
	pair<int, int> topmost = {-1, -1};
	pair<int, int> leftmost = {-1, -1};
	bool ok = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'R') {
				topmost = {i, j};
				ok = true;
				break;
			}
		}
		if (ok) break;
	}
	ok = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[j][i] == 'R') {
				leftmost = {j, i};
				ok = true;
				break;
			}
		}
		if (ok) break;
	}
	if (topmost == leftmost) cout << "YES\n";
	else cout << "NO\n";
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