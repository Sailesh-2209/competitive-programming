#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	int ans = 20;
	for (int numMul = 0; numMul < 16; numMul++) {
		for (int numAdd = 0; numAdd < 16; numAdd++) {
			if (((n + numAdd) << numMul) % 32768 == 0) {
				ans = min(ans, numAdd + numMul);
			}
		}
	}
	cout << ans << ' ';
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