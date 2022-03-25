#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, k; cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long left = k + 1;
	long long amount = 0;
	for (int i = 0; i < n - 1; i++) {
		long long val1 = ceil(pow(10, a[i + 1]));
		long long val2 = ceil(pow(10, a[i]));
		long long notes = min(left, (val1 / val2 - 1));
		left -= notes;
		amount += (val2 * notes);
	}
	amount += (ceil(pow(10, a[n - 1])) * left);
	cout << amount << '\n';
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