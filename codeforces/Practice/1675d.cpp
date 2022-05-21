#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << 1 << '\n' << 1 << '\n' << 1 << '\n';
		cout << '\n';
		return;
	}
	set<int> s(a.begin(), a.end());
	vector<bool> v(n + 1, false);
	vector<int> leaf;
	for (int i = 1; i <= n; i++)
		if (s.find(i) == s.end()) leaf.push_back(i);
	cout << leaf.size() << '\n';
	for (int node : leaf) {
		vector<int> path;
		int cur = node;
		while (!v[cur]) {
			if (a[cur] == cur) {
				path.push_back(cur);
				v[cur] = true;
				break;
			}
			path.push_back(cur);
			v[cur] = true;
			cur = a[cur];
		}
		cout << path.size() << '\n';
		reverse(path.begin(), path.end());
		for (int val : path)
			cout << val << ' ';
		cout << '\n';
	}
	cout << '\n';
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