#include <bits/stdc++.h>

using namespace std;

int search(int val, vector<long long> pref) {
	int n = (int) pref.size();
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (pref[mid] >= val) hi = mid;
		else lo = mid + 1;
	}
	return lo + 1;
}

void solve() {
	int nv, nq; cin >> nv >> nq;
	vector<long long> vals(nv);
	vector<long long> qers(nq);
	vector<long long> pref(nv);
	for (int i = 0; i < nv; i++)
		cin >> vals[i];
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	pref[0] = vals[0];
	for (int i = 1; i < nv; i++)
		pref[i] = pref[i - 1] + vals[i];
	for (int i = 0; i < nq; i++) {
		int x; cin >> x;
		if (x > pref[nv - 1]) {
			cout << "-1\n";
			continue;
		}
		int ind = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
		cout << (ind + 1) << '\n';;
	}
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