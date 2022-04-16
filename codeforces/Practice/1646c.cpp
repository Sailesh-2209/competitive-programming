/**
 * find all the factorials smaller than N
 * minimize value of numPowers + numFactorials
**/

#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 9;

vector<long long> factorials(long long n) {
	vector<long long> res;
	long long num = 1;
	long long mul = 1;
	while (num <= n) {
		res.push_back(num);
		mul++;
		num *= mul;
	}
	return res;
}

vector<int> decToBin(int num, int n) {
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {
		res.push_back(num >> i & 1);
	}
	return res;
}

int numOnes(long long num, set<long long> s) {
	int ans = 0;
	for (int i = 0; i < 45; i++) {
		if (num >> i & 1) {
			if (s.find(1 << i) != s.end()) {
				return -1;
			}
			ans++;
		}
	}
	return ans;
}

void solve() {
	long long n; cin >> n;
	vector<long long> f = factorials(n);
	int sz = (int) f.size();
	int ans = nax;
	for (int mask = (1 << sz); mask < (1 << (sz + 1)); mask++) {
		vector<int> bits = decToBin(mask, sz);
		long long sum = 0;
		int cur = 0;
		set<long long> s;
		for (int i = 0 ; i < sz; i++) {
			if (bits[i] == 1) {
				cur++;
				sum += f[i];
				s.insert(f[i]);
			}
		}
		long long diff = n - sum;
		int numPowers = numOnes(diff, s);
		if (numPowers >= 0) {
			cur += numPowers;
			ans = min(ans, cur);
		}
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