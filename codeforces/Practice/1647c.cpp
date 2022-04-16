#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	if (board[0][0] == '1') {
		cout << "-1\n";
		return;
	}
	vector<pair<pair<int, int>, pair<int, int>>> ops;
	for (int col = m - 1; col > 0; col--) {
		for (int row = 0; row < n; row++) {
			if (board[row][col] == '1') {
				ops.push_back(make_pair(make_pair(row + 1, col), make_pair(row + 1, col + 1)));
			}
		}
	}
	for (int row = n - 1; row > 0; row--) {
		int col = 0;
		if (board[row][col] == '1') {
			ops.push_back(make_pair(make_pair(row, col + 1), make_pair(row + 1, col + 1)));
		}
	}
	int sz = (int) ops.size();
	cout << sz << '\n';
	for (auto op : ops) {
		cout << op.first.first << ' ';
		cout << op.first.second << ' ';
		cout << op.second.first << ' ';
		cout << op.second.second << '\n';
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