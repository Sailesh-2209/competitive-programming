/**
 * author		: sailboat22
 * timestamp	: 25 January 2022 (Tuesday) 18:43 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int max_ele = 0;
	int min_ele = 1e9 + 5;
	while (n--) {
		int num;
		cin >> num;
		max_ele = max(max_ele, num);
		min_ele = min(min_ele, num);
	}
	cout << (max_ele - min_ele) << '\n';
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
