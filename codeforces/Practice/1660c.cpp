#include <bits/stdc++.h>

using namespace std;

int findNextIndex(char c) {
	return c - 'a';
}

void solve() {
	string s; cin >> s;
	vector<bool> prev(26, false);
	int n = s.size();
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (prev[s[i] - 'a']) {
			m += 2;
			for (int j = 0; j < 26; j++) {
				prev[j] = false;
			}
		} else {
			prev[s[i] - 'a'] = true;
		}
	}
	int ans = n - m;
	cout << ans << '\n'
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