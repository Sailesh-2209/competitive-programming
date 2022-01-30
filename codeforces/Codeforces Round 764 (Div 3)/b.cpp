/**
 * author		: sailboat22
 * timestamp	: 25 January 2022 (Tuesday) 18:50 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	// keep b c the same, change a
	int expected_a = b - (c - b);
	if (expected_a >= a && expected_a % a == 0 && expected_a != 0) {
		cout << "YES\n";
		return;
	}

	// keep a c the same, change b
	int expected_b = a + ((c - a) / 2);
	if (expected_b >= b && expected_b % b == 0 && (c - a) % 2 == 0 && expected_b != 0) {
		cout << "YES\n";
		return;
	}

	// keep a b the same, change c
	int expected_c = b + (b - a);
	if (expected_c >= c && expected_c % c == 0 && expected_c != 0) {
		cout << "YES\n";
		return;
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
