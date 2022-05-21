#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	if (n < 1400) cout << "Division 4\n";
	else if (n >= 1400 && n < 1600) cout << "Division 3\n";
	else if (n >= 1600 && n < 1900) cout << "Division 2\n";
	else cout << "Division 1\n";
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