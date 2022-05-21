#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	map<int, int> counts;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counts[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (counts[a[i]] > 2) {
			cout << a[i] << '\n';
			return;
		}
	}
	cout << "-1\n";
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