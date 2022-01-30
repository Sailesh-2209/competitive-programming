/**
 * author		: sailboat22
 * timestamp	: 27 January 2022 (Thursday) 11:11 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	bool f1 = (a == b) && (c % 2 == 0);
	bool f2 = (a == c) && (b % 2 == 0);
	bool f3 = (b == c) && (a % 2 == 0);
	bool f4 = a == b + c;
	bool f5 = b == a + c;
	bool f6 = c == a + b;
	if (f1 || f2 || f3 || f4 || f5 || f6)
		cout << "YES\n";
	else
		cout << "NO\n";
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
