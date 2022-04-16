/**
 * if 1 not in array then NO
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, c; cin >> n >> c;
	vector<int> a(n);
	vector<int> counts(c + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counts[a[i]]++;
	}
	vector<int> pre(c + 1, 0);
	for (int i = 1; i <= c; i++) {
		pre[i] = counts[i] + pre[i - 1];
	}
	for (int i = 1; i <= c; i++) {
		if (counts[i] == 0) {
			continue;
		}
		for (int j = i; j <= c; j += i) {
			long long l = j;
			long long r = min(j + i - 1, c);
			if (pre[r] - pre[l - 1] > 0 && counts[j / i] == 0) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
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