#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> next(n);
	int prev = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == ')') {
			next[i] = prev;
			prev = i;
		}
	}
	int ops = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			if (i == n - 1) {
				cout << ops << " 1\n";
				return;
			} else {
				ops++; i++;
			}
		} else {
			if (i == n - 1) {
				cout << ops << " 1\n";
				return;
			} else {
				if (s[i + 1] == ')') {
					ops++; i++;
				} else {
					int nx = next[i];
					if (nx == -1) {
						int ans = n - i;
						cout << ops << ' ' << ans << '\n';
						return;
					} else {
						ops++; i = nx;
					}
				}
			}
		}
	}
	cout << ops << " 0\n";
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