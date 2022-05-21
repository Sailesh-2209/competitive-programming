#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int c = 0;
	for (int num : a)
		if (num == 0) c++;
	if (c > 0) {
		cout << (n - c) << '\n';
		return;
	}
	bool ok = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (a[i] == a[j]) ok = true;
		}
	}
	if (ok) {
		cout << n << '\n';
	} else {
		cout << (n + 1) << '\n';
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