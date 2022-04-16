#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<int> qx(q), qy(q);
	for (int i = 0; i < q; i++) {
		cin >> qx[i] >> qy[i];
	}
	int ans = 1;
	set<int> rowset, colset;
	for (int i = q - 1; i >= 0; i--) {
		bool ok = false;
		if (rowset.find(qx[i]) == rowset.end()) {
			rowset.insert(qx[i]);
			ok = true;
		}
		if (colset.find(qy[i]) == colset.end()) {
			colset.insert(qy[i]);
			ok = true;
		}
		if (ok) {
			ans = (ans * 1LL * k) % mod;
		}
		if (int(rowset.size()) == n || int(colset.size()) == m) {
			break;
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
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}