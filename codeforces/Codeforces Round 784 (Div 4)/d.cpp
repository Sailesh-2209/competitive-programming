#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int i = 0;
	while (i < n) {
		int j = i + 1;
		while (j < n && s[j] != 'W') j++;
		int rc = 0, bc = 0;
		for (int c = i; c < j; c++) {
			if (s[c] == 'R') rc++;
			else if (s[c] == 'B') bc++;
		}
		if ((rc == 0 && bc != 0) || (bc == 0 && rc != 0)) {
			cout << "NO\n";
			// cout << "rc: " << rc << " bc: " << bc << endl;
			// cout << "i: " << i << " j: " << j << endl;
			return;
		}
		i = j + 1;
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