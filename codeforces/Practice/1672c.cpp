#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = -1, r = -1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			if (l == -1) l = i;
			r = i;
		}
	}
	if (r == l) {
		cout << "0\n";
	} else {
		int ans = max(r - l - 1, 1);
		cout << ans << '\n';
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