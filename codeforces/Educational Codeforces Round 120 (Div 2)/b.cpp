/**
 * author		: sailboat22
 * timestamp	: 27 January 2022 (Thursday) 11:31 
**/

#include <bits/stdc++.h>

using namespace std;

int sort_order(const vector<int> &v1, const vector<int> &v2) {
	return v1[0] < v2[0];
}

void solve() {
	int n; cin >> n;
	vector<int> rating(n);
	for (int i = 0; i < n; i++) cin >> rating[i];
	string s; cin >> s;
	vector<vector<int>> liked;
	vector<vector<int>> disliked;
	for (int i = 0; i < n; i++) {
		vector<int> ind;
		ind.push_back(rating[i]);
		ind.push_back(i);
		if (s[i] == '1') {
			liked.push_back(ind);
		} else {
			disliked.push_back(ind);
		}
	}
	sort(liked.begin(), liked.end(), sort_order);
	sort(disliked.begin(), disliked.end(), sort_order);
	vector<int> result(n, 0);
	int sz = disliked.size();
	int r = 1;
	for (int i = 0; i < sz; i++) {
		result[disliked[i][1]] = r;
		r++;
	}
	sz = liked.size();
	for (int i = 0; i < sz; i++) {
		result[liked[i][1]] = r;
		r++;
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	cout << '\n';
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
