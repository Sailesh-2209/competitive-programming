#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int> &a, int lo, int mid, int hi) {
	vector<int> l, r;
	long long inv = 0;
	for (int i = lo; i <= mid; i++)
		l.push_back(a[i]);
	for (int i = mid + 1; i <= hi; i++)
		r.push_back(a[i]);
	int p1 = 0, p2 = 0;
	int m = (int) l.size(), n = (int) r.size();
	int i = lo;
	while (p1 < m && p2 < n) {
		if (l[p1] < r[p2]) {
			a[i++] = l[p1++];
		} else {
			a[i++] = r[p2++];
			inv += mid - lo + 1 - p1;
		}
	}
	while (p1 < m)
		a[i++] = l[p1++];
	while (p2 < n)
		a[i++] = r[p2++];
	return inv;
}

long long mergesort(vector<int> &a, int lo, int hi) {
	if (lo >= hi) return 0;
	long long inv = 0;
	int mid = lo + (hi - lo) / 2;
	inv += mergesort(a, lo, mid);
	inv += mergesort(a, mid + 1, hi);
	inv += merge(a, lo, mid, hi);
	return inv;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long ans = mergesort(a, 0, n - 1);
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