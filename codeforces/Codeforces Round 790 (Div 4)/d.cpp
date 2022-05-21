#include <bits/stdc++.h>

using namespace std;

void solve() {
	int nr, nc; cin >> nr >> nc;
	vector<vector<int>> grid(nr, vector<int> (nc, 0));
	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			cin >> grid[r][c];
		}
	}
	int ans = 0;
	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			int sum = grid[r][c];
			for (int rdir : {1, -1}) {
				for (int cdir : {1, -1}) {
					int curr = r + rdir, curc = c + cdir;
					while (0 <= curr && curr < nr && 0 <= curc && curc < nc) {
						sum += grid[curr][curc];
						curr += rdir; curc += cdir;
					}
				}
			}
			ans = max(ans, sum);
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