/**
 * all odd numbers are YES
**/

#include <bits/stdc++.h>

using namespace std;

long long calc(long long num) {}

void solve() {
	long long n; cin >> n;
	if (n & 1) {
		cout << "2\n";
		return;
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