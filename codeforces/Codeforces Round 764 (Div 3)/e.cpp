/**
 * author		: sailboat22
 * timestamp	: 26 January 2022 (Wednesday) 21:17 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	map<string, vector<int>> num_map;
	for (int i = 0; i < n; i++) {
		string ele; cin >> ele;
		for (int j = 0; j + 2 <= m; j++) {
			vector<int> temp_len2 { j + 1, j + 2, i + 1 };
			num_map.insert({ele.substr(j, 2), temp_len2});
			if (j + 3 <= m) {
				vector<int> temp_len3 { j + 1, j + 3, i + 1 };
				num_map.insert({ele.substr(j, 3), temp_len3});
			}
		}
	}
	string num; cin >> num;
	vector<vector<int>> result;
	vector<bool> dp(m + 1, false);
	dp[0] = true; dp[1] = true;
	for (int i = 2; i <= m; i++) {
		string key1 = num.substr(i - 2, 2);
		string key2 = "";
		bool f1 = dp[i - 2];
		bool f2 = num_map.find(key1) != num_map.end();
		bool f3 = false;
		bool f4 = false;
		if (i > 2) {
			key2 = num.substr(i - 3, 3);
			f3 = dp[i - 3];
			f4 = num_map.find(key2) != num_map.end();
		}
		if (f1 && f2) {
			vector<int> newind = num_map[key1];
			vector<int> dummy { -1, -1, -1 };
			vector<int> oldind = result.empty() ? dummy : result.back();
			if (newind[2] == oldind[2]) {
				result.pop_back();
				vector<int> v { oldind[0], newind[1], newind[2] };
				result.push_back(v);
			} else {
				result.push_back(newind);
			}
			dp[i] = true;
		} else if (f3 && f4) {
			vector<int> newind = num_map[key2];
			vector<int> dummy { -1, -1, -1 };
			vector<int> oldind = result.empty() ? dummy : result.back();
			if (newind[2] == oldind[2]) {
				result.pop_back();
				vector<int> v { oldind[0], newind[1], newind[2] };
				result.push_back(v);
			} else {
				result.push_back(newind);
			}
			dp[i] = true;
		}
	}
	if (dp[m]) {
		int size = result.size();
		cout << size << '\n';
		for (int i = 0; i < size; i++) {
			cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << '\n';
		}
	} else {
		cout << "-1\n";
	}
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
