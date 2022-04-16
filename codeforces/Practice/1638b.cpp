#include <bits/stdc++.h>

using namespace std;

const int nax = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set<int> eset, oset;
	eset.insert(nax + 1);
	oset.insert(nax);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] % 2 == 0) {
			if (*eset.begin() < a[i]) {
				cout << "NO\n"; return;
			}
			eset.insert(a[i]);
		} else {
			if (*oset.begin() < a[i]) {
				cout << "NO\n"; return;
			}
			oset.insert(a[i]);
		}
	}
	cout << "YES\n";
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