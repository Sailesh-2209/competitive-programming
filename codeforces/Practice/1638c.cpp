/**
 * Algo:
 * maintain set
 * for each new num, if this num is greater than largest num in set, add to set
 * if there is a number greater than current num in set, merge all of the components
 * to its right
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	int mx = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		mx = max(mx, num);
		ans += (mx == i);
	}
	cout << ans << '\n';
}

void solve2() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> oset;
	oset.insert(a[0]);
	for (int i = 1; i < n; i++) {
		int maxEle = *oset.rbegin();
		if (a[i] > maxEle) {
			oset.insert(a[i]);
		} else {
			auto it = lower_bound(oset.begin(), oset.end(), a[i]);
			vector<int> rem;
			while (it != oset.end()) {
				rem.push_back(*it);
				it++;
			}
			for (int num : rem) 
				oset.erase(num);
			oset.insert(maxEle);
		}
	}
	cout << oset.size() << '\n';
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