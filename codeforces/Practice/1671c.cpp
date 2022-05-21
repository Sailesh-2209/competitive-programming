#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, x; cin >> n >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<long long> pre(n, 0);
	pre[0] = a[0];
	for (int i = 1; i < n; i++) 
		pre[i] = a[i] + pre[i - 1];
	long long ans = 0;
	long long ex = 0;
	long long i = n - 1;
	while (i >= 0) {
		long long cost = pre[i] + (i + 1) * ex;
		if (cost > x) {
			i--;
		} else {
			long long new_ex = (x - cost) / (i + 1);
			ans += (i + 1) * 1LL * (new_ex + 1);
			ex += new_ex + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	long long t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}