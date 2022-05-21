/**
 * cost is max of 0s left or 1s removed
 * initial cost = number of 0s to right of 1st 1 and left of last 1
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	int a = 0; // ones removed
	int b = 0; // zeros left;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') b++;
	}
	int cost = a + b;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') b--;
		else a++;
		cost = min(cost, a + b);
	}
	a = 0;
	b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') b++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') b--;
		else a++;
		cost = min(cost, a + b);
	}
	cout << cost << '\n';
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