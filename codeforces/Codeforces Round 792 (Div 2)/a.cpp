#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	int sz = (int) s.size();
	if (sz == 2) {
		cout << s[1] << '\n';
		return;
	}
	int minn = 11;
	for (char c : s)
		minn = min(minn, c - '0');
	cout << minn << '\n'; 
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