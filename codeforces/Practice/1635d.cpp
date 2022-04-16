/**
 * let dp[i] represent the number of elements in the set in the range [2^(i-1), 2^i)
 * 
 * a number y can belong to a range if
 * 1. y is in the set
 * 2. y is odd and (y-1)/2 is in the set
 * 3. y is even and y/4 is in the set
 * 
 * dp[i] = dp[i - 1] + dp[i - 2] + number of elems in [2^(i-1), 2^i) - overcounts
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

bool can(int n, unordered_set<int> s) {
	if (n == 0) return false;
	if (s.find(n) != s.end()) return true;
	bool ans = false;
	if (n % 4 == 0) {
		ans |= can(n / 4, s);
	} else if (n % 2 == 1) {
		ans |= can((n - 1) / 2, s);
	}
	return ans;
}

void solve() {
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	vector<int> dp(p + 1, 0);
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	int p1 = 0, p2 = 1;
	while (p1 < n) {
		int lo = (1 << (p2 - 1));
		int hi = (1 << p2);
		int count = 0;
		while (p1 < n && lo <= a[p1] && a[p1] < hi) {
			if (a[p1] % 4 == 0 && can(a[p1] / 4, s)) count++;
			else if (a[p1] % 2 == 1 && can((a[p1] - 1) / 2, s)) count++;
			p1++;
		}
		dp[p2] = count;
		p2++;
	}
	for (int i = 1; i <= p; i++) {
		dp[i] = (dp[i] + ((i - 1 > 0) ? dp[i - 1] : 0) + (dp[i - 2] > 0 ? dp[i - 2] : 0)) % mod;
	}
	int ans = 0;
	for (int i = 0; i <= p; i++) {
		ans = (ans + dp[i]) % mod;
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
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}