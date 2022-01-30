/**
 * author		: sailboat22
 * timestamp	: 27 January 2022 (Thursday) 10:09 
**/

#include <bits/stdc++.h>

using namespace std;

void query(int num) {
	cout << "+ " << num << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int lo = 1, hi = n;
	int div = 0;
	while (hi - lo > 1) {
		int mid = (hi - lo) / 2;
		query(n - mid);
		int d; cin >> d;
		if (d > div) lo = mid;
		else hi = mid;
		lo = (lo + n - mid) % n;
		hi = (hi + n - mid) % n;
		div = d;
		if (hi == 0) hi = n;
	}
	cout << "! " << div * n + lo;
	return 0;
}
