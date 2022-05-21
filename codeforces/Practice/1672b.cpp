#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	bool ok = (*s.rbegin() == 'B');
	int cnt = 0;
	for (char c : s) {
		if (c == 'A') cnt++;
		else cnt--;
		if (cnt < 0) ok = false;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
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