#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	map<int, int> counts;
	for (int i = 0; i < n; i++)
		counts[a[i]]++;
	int ans = -1;
	int l = -1, r = -1;
	int i = 0;
	while (i < n) {
		int start = i;
		if (counts[a[i]] < k) {
			i++; continue;
		}
		i++;
		while (i < n && counts[a[i]] >= k && (a[i] == a[i - 1] + 1)) {
			int num = a[i];
			while (i < n && a[i] == num) i++;
			i++;
			i = min(i, n);
		}
		if (i - start > ans) {
			ans = i - start;
			l = a[start];
			r = a[i];
		}
	}
	if (ans == -1) cout << "-1\n";
	else cout << l << ' ' << r << '\n'; 
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