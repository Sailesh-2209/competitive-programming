#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	long long sum = 0;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	priority_queue<long long> aq;
	priority_queue<long long> bq(a.begin(), a.end());
	aq.push(sum);
	while (!aq.empty() && !bq.empty()) {
		long long elea = aq.top(); aq.pop();
		long long eleb = bq.top(); bq.pop();
		if (eleb > elea) {
			cout << "NO\n";
			return;
		} else if (elea == eleb) {
			continue;
		} else {
			bq.push(eleb);
			if (elea % 2 == 0) {
				aq.push(elea / 2);
				aq.push(elea / 2);
			} else {
				aq.push((elea + 1) / 2);
				aq.push((elea - 1) / 2);
			}
		}
	}
	if (aq.empty() && bq.empty()) cout << "YES\n";
	else cout << "NO\n";
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