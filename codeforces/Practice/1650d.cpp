#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ans(n + 1, 0);
	for (int i = n; i > 0; i--) {
		int count = 0;
		while (a[i] != i) {
			if (count == n) {
				cout << "-1\n";
				return;
			}
			count++;
			int key = a[1];
			for (int j = 1; j < i; j++) {
				a[j] = a[j + 1];
			}
			a[i] = key;
		}
		ans[i] = count;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
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