#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> p(n + 1);
	for (int i = 2; i <= n; i++)
		cin >> p[i];
	string c; cin >> c;
	c.insert(0, "a");
	vector<vector<int>> children(n + 1);
	for (int i = 2; i <= n; i++)
		children[p[i]].push_back(i);
	queue<int> q;
	stack<int> s;
	q.push(1);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		s.push(node);
		for (int child : children[node]) 
			q.push(child);
	}
	vector<pair<int, int>> counts(n + 1, {0, 0});
	int ans = 0;
	while (!s.empty()) {
		int node = s.top(); s.pop();
		int wc = 0; int bc = 0;
		for (int child : children[node]) {
			wc += counts[child].first;
			bc += counts[child].second;
		}
		if (c[node] == 'W') wc++;
		else bc++;
		counts[node].first = wc;
		counts[node].second = bc;
		if (wc == bc) ans++;
	}
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