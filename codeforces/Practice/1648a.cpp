#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 3;

void solve() {
	int m, n; cin >> m >> n;
	vector<vector<int>> grid(m, vector<int> (n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	set<int> colors;
	vector<vector<int>> rows(sz);
	vector<vector<int>> cols(sz);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			colors.insert(grid[i][j]);
			rows[grid[i][j]].push_back(i);
			cols[grid[i][j]].push_back(j);
		}
	}
	for (auto color : colors) {
		sort(rows[color].begin(), rows[color].end());
		sort(cols[color].begin(), cols[color].end());
	}
	long long ans = 0;
	for (auto color : colors) {
		int len = (int) rows[color].size();
		long long sum = 0;
		for (int i = 0; i < len; i++) {
			sum += 1LL * (2 * i + 1 - len) * rows[color][i];
			sum += 1LL * (2 * i + 1 - len) * cols[color][i];
		}
		ans += sum;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t = 1; //  cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}