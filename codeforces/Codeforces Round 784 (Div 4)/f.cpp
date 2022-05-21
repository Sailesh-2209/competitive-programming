#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	vector<int> pre(n, 0);
	vector<int> suf(n, 0);
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + w[i];
	for (int i = n - 2; i >= 0; i--)
		suf[i] = suf[i + 1] + w[i];
	int a = 0, b = n - 1;
	int pa = a, pb = b;
	while (a < b) a++;
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