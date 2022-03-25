#include <bits/stdc++.h>

using namespace std;

void solve() {
	int m, n; cin >> m >> n;
	vector<vector<vector<int>>> a(m, vector<vector<int>> (n, vector<int> (4, 0)));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			for (int k = 0; k < 4; k++) {
				if ((x >> k) & 1) a[i][j][k] = 1;
			}
		}
	}
	set<pair<int, int>> v;
	vector<int> result;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v.find(make_pair(i, j)) != v.end()) {
				continue;
			}
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			v.insert(make_pair(i, j));
			int count = 0;
			while (!q.empty()) {
				count++;
				pair<int, int> curr = q.front();
				q.pop();
				int x = curr.first, y = curr.second;
				if (x + 1 < m && a[x][y][1] == 0 && a[x + 1][y][3] == 0) {
					if (v.find(make_pair(x + 1, y)) == v.end()) {
						q.push(make_pair(x + 1, y));
						v.insert(make_pair(x + 1, y));
					}
				}
				if (x - 1 >= 0 && a[x][y][3] == 0 && a[x - 1][y][1] == 0) {
					if (v.find(make_pair(x - 1, y)) == v.end()) {
						q.push(make_pair(x - 1, y));
						v.insert(make_pair(x - 1, y));
					}
				}
				if (y + 1 < n && a[x][y][2] == 0 && a[x][y + 1][0] == 0) {
					if (v.find(make_pair(x, y + 1)) == v.end()) {
						q.push(make_pair(x, y + 1));
						v.insert(make_pair(x, y + 1));
					}
				}
				if (y - 1 >= 0 && a[x][y][0] == 0 && a[x][y - 1][2] == 0) {
					if (v.find(make_pair(x, y - 1)) == v.end()) {
						q.push(make_pair(x, y - 1));
						v.insert(make_pair(x, y - 1));
					}
				}
			}
			result.push_back(count);
		}
	}
	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());
	for (int num : result) {
		cout << num << ' ';
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
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}