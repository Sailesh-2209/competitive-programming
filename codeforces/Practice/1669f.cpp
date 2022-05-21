#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p1 = 0, p2 = n - 1;
	int w1 = a[p1], w2 = a[p2];
	int ans = 0;
	while (p1 != p2) {
		if (w1 == w2) {
			ans = p1 + n - p2 + 1;
		}
		if (w1 < w2) w1 += a[++p1];
		else w2 += a[--p2];
	}
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