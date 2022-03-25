#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long ans = power(a, b / 2);
	ans *= ans;
	ans %= mod;
	if (b % 2) {
		ans *= a;
	}
	return ans % mod;
}

void solve() {
	long long k; cin >> k;
	long long exp = (1LL << k) - 2;
	long long ans = power(4, exp);
	ans *= 6;
	ans %= mod;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}