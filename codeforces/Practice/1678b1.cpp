#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int i = 0;
	int ops = 0;
	while (i < n) {
		char c = s[i];
		int count = 0;
		while (i < n && s[i] == c) {
			count++; i++;
		}
		if (count % 2 == 1) {
			s[i] = c;
			ops++;
			i++;
		}
	}
	cout << ops << '\n';
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