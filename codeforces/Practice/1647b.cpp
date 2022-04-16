#include <bits/stdc++.h>

using namespace std;

void solve() {
	int numrows, numcols; cin >> numrows >> numcols;
	vector<string> board(numrows);
	for (int row = 0; row < numrows; row++) {
		cin >> board[row];
	}
	for (int row = 0; row < numrows; row++) {
		for (int col = 0; col < numcols; col++) {
			int a = board[row][col] - '0';
			int b = (row + 1 < numrows) ? board[row + 1][col] - '0' : 0;
			int c = (col + 1 < numcols) ? board[row][col + 1] - '0' : 0;
			int d = (row + 1 < numrows && col + 1 < numcols) ? board[row + 1][col + 1] - '0' : 0;
			if (a + b + c + d == 3) {
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