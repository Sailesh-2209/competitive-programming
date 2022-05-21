#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, m; cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	long long tot = n;
	for (int i = 0; i < n; i++) {
		tot += max(a[i], a[(i + 1) % n]);
	}
	// cout << tot << '\n';
	if (tot > m) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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