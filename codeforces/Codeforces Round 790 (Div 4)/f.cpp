#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	map<int, int> counts;
	for (int i = 0; i < n; i++)
		counts[a[i]]++;
	set<int> s(a.begin(), a.end());
	vector<int> ua(s.begin(), s.end());
	int sz = (int) ua.size();
	int l = 0, r = -1;
	int i = 0;
	while (i < sz) {
		int start = i;
		if (counts[ua[i]] < k) {
			i++;
			continue;
		}
		while (i + 1 < n && ua[i + 1] == ua[i] + 1 && counts[ua[i + 1]] >= k) i++;
		if (i - start > r - l) {
			l = start; r = i;
		}
		i++;
	}
	if (r - l == -1) cout << "-1\n";
	else cout << ua[l] << ' ' << ua[r] << '\n';
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