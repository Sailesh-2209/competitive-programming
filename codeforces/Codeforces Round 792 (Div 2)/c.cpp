#include <bits/stdc++.h>

using namespace std;

void solve() {
	int nr, nc; cin >> nr >> nc;
	vector<vector<int>> grid(nr, vector<int> (nc));
	for (int r = 0; r < nr; r++)
		for (int c = 0; c < nc; c++)
			cin >> grid[r][c];
	vector<vector<int>> sgrid(nr, vector<int> (nc));
	for (int r = 0; r < nr; r++)
		for (int c = 0; c < nc; c++)
			sgrid[r][c] = grid[r][c];
	for (int r = 0; r < nr; r++)
		sort(sgrid[r].begin(), sgrid[r].end());
	for (int r = 0; r < nr; r++) {
		int num = 0;
		for (int c = 0; c < nc; c++) {
			if (sgrid[r][c] != grid[r][c]) num++;
		}
		if (num > 2) {
			cout << "-1\n";
			return;
		}
	}
	int in1 = -1, in2 = -1;
	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			if (sgrid[r][c] != grid[r][c]) {
				if (in1 == -1) {
					in1 = c;
				} else {
					in2 = c;
					break;
				}
			}
		}
		if (in1 > -1) break;
	}
	if (in1 == -1) {
		cout << "1 1\n";
		return;
	}
	for (int r = 0; r < nr; r++) {
		if (grid[r][in1] < grid[r][in2]) {
			cout << "-1\n";
			return;
		}
	}
	cout << ++in1 << ' ' << ++in2 << '\n';
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