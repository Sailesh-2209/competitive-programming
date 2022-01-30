/**
 * author		: sailboat22
 * timestamp	: 26 January 2022 (Wednesday) 16:55 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int counts[26] = {0};
	for (char c : s) 
		counts[c - 'a']++;
	int odds = 0, evens = 0;
	for (int i = 0; i < 26; i++) {
		evens += counts[i] / 2;
		odds += counts[i] % 2;
	}
	int ans = 2 * (evens / k);
	odds += 2 * (evens % k);
	if (odds >= k) ans++;
	cout << ans << '\n';
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
