#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	bool one = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) one = true;
	}
	sort(a.begin(), a.end());
	bool ok = false;
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] == a[i] + 1) ok = true;
	}
	if (!one) {
		cout << "YES\n";
	} else {
		if (!ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
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