#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	if (n < 4) {
		cout << "YES\n";
		return;
	}
	int a = s[0] - '0';
	int b = s[1] - '0';
	int c = s[2] - '0';
	int d = s[n - 1] - '0';
	int e = s[n - 2] - '0';
	int f = s[n - 3] - '0';
	if (a + b + c == d + e + f) cout << "YES\n";
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