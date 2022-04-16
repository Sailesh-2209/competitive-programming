#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(2));
	map<int, int> ind;
	for (int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
		ind[a[i][0]] = i;
	}
	sort(a.begin(), a.end(), [] (const vector<int> v1, const vector<int> v2) {
		return v1[1] < v2[1];
	});
	long long tot = 0;
	for (int i = 0; i < 2 * n; i++) {
		tot += 1LL * a[i][1];
	}
	sort(a.begin(), a.begin() + 2 * n, [] (const vector<int> v1, const vector<int> v2) {
		return v1[0] < v2[0];
	});
	cout << tot << '\n';
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = 2 * n - 1 - i;
		cout << (ind[a[l][0]] + 1) << ' ' << (ind[a[r][0]] + 1) << '\n';
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