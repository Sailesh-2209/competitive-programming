/**
 * author		: sailboat22
 * timestamp	: 27 January 2022 (Thursday) 12:12 
**/

#include <bits/stdc++.h>

using namespace std;

long long floor_div(long long num, long long den) {
	long long div = num / den;
	while (div * den > num) div--;
	return div;
}

void solve() {
	long long n, k;
	cin >> n >> k;
	vector<long long> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	vector<long long> prefix_sums(n + 1, 0);
	for (int i = 0; i < n; i++) {
		prefix_sums[i + 1] = prefix_sums[i] + nums[i];
	}
	long long result = 1e18 + 5;
	for (long long y = 0; y < n; y++) {
		long long num = k - prefix_sums[n - y] + nums[0];
		long long den = y + 1;
		long long x = nums[0] - floor_div(num, den);
		result = min(result, max(x, 0LL) + y);
	}
	cout << result << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
