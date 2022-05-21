#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	int i = 0;
	while (i < n) {
		char c = s[i];
		int count = 0;
		while (i < n && s[i] == c) {
			i++; count++;
		}
		if (count == 1) {
			cout << "NO\n";
			return;
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