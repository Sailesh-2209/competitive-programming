/**
 * sort it at the time of storing in the array
 * there can only be 26 * 26 unique values
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<string> a(n);
	map<string, int> counts;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counts[a[i]]++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		// long long count = 0;
		char c1 = a[i][0], c2 = 'a';
		for (int z = 0; z < 26; z++) {
			string temp; temp.push_back(c1); temp.push_back(c2);
			if (a[i] != temp) {
				ans += counts[temp];
			}
			c2++;
		}
		c1 = a[i][1], c2 = 'a';
		for (int z = 0; z < 26; z++) {
			string temp; temp.push_back(c1); temp.push_back(c2);
			if (a[i] != temp) {
				ans += counts[temp];
			}
			c2++;
		}
		c1 = 'a', c2 = a[i][0];
		for (int z = 0; z < 26; z++) {
			string temp; temp.push_back(c1); temp.push_back(c2);
			if (a[i] != temp) {
				ans += counts[temp];
			}
			c1++;
		}
		c1 = 'a', c2 = a[i][1];
		for (int z = 0; z < 26; z++) {
			string temp; temp.push_back(c1); temp.push_back(c2);
			if (a[i] != temp) {
				ans += counts[temp];
			}
			c1++;
		}
	}
	ans /= 2;
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