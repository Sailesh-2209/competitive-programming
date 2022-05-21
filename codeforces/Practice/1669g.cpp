#include <bits/stdc++.h>

using namespace std;

void solve() {
	int nrows, ncols; cin >> nrows >> ncols;
	vector<string> grid(nrows);
	for (int i = 0; i < nrows; i++)
		cin >> grid[i];
	for (int col = 0; col < ncols; col++) {
		int start = nrows - 1;
		while (start >= 0) {
			int i = start;
			int count = 0;
			while (i >= 0 && grid[i][col] != 'o') {
				if (grid[i][col] == '*') count++;
				grid[i][col] = '.';
				i--;
			}
			while (count-- && start >= 0)
				grid[start--][col] = '*';
			start = i - 1;
		}
	}
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncols; col++) {
			cout << grid[row][col];
		}
		cout << '\n';
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