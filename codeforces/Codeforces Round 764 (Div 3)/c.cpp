/**
 * author		: sailboat22
 * timestamp	: 26 January 2022 (Wednesday) 14:39 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
		return a > b;
	});
	vector<bool> used (n + 1, false);
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n) {
			if (!used[arr[i]]) {
				used[arr[i]] = true;
			} else {
				int x = arr[i];
				while (used[x]) x /= 2;
				if (x == 0) {
					cout << "NO\n";
					return;
				} else {
					used[x] = true;
				}
			}
		} else {
			int x = arr[i];
			while (x > n || used[x]) {
				x /= 2;
			}
			if (x == 0) {
				cout << "NO\n";
				return;
			} else {
				used[x] = true;
			}
		}
	}
	cout << "YES\n";
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
