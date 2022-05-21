#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long z = c;
	long long y = z + b;
	long long x = y + a;
	cout << x << ' ' << y << ' ' << z << '\n';
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