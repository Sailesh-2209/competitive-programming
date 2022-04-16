#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	long long sum = 0;
	long long nax = -1;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		sum += num;
		nax = max(nax, num);
	}
	if (sum == 0) {
		cout << "0\n";
		return;
	}
	// sum -= nax;
	if (2 * nax <= sum) cout << "1\n";
	else cout << (2 * nax - sum) << '\n';
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