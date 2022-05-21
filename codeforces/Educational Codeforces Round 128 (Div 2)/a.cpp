#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((c >= a && c <= b) || (d >= a && c <= b)) {
		cout << max(a, c) << '\n';
	} else {
		cout << (a + c) << '\n';
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