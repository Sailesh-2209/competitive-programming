/**
 * https://codeforces.com/problemset/problem/1605/C
 * 
 * first letter has to be a
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; string a;
	cin >> n >> a;
	int ans = 8;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'a') {
			if (i + 1 < n && a[i + 1] == 'a') {
				ans = min(ans, 2);
			} else if (i + 2 < n && a[i + 2] == 'a') {
				ans = min(ans, 3);
			} else if (i + 3 < n && a[i + 3] == 'a') {
				if (a[i + 1] != a[i + 2]) {
					ans = min(ans, 4);
				} else {
					if (i + 6 < n && a[i + 6] == 'a' && a[i + 1] != a[i + 4] && a[i + 1] != a[i + 5]) {
						ans = min(ans, 7);
					}
				}
			}
		}
	}
	if (ans == 8) {
		cout << -1 << '\n';
	} else {
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

