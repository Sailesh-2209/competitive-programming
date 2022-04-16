#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 3 && a[1] % 2 == 1) {
		cout << "-1\n"; return;
	}
	long long s = 0;
	for (int i = 1; i < n - 1; i++)
		s += a[i];
	if (s == n - 2) {
		cout << "-1\n";
		return;
	}
	long long ans = 0;
	for (int i = 1; i < n - 1; i++)
		ans += (a[i] + 1) / 2;
	cout << ans << '\n';
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