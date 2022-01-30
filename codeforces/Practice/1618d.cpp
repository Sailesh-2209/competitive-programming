/**
 * author       : sailboat22
 * timestamp    : 29 January 2022 (Saturday) 15:55 
**/

#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2 * k; i++) {
        result += nums[i];
    }
    for (int i = 0; i < k; i++) {
        result += nums[n - 2 * k + i] / nums[n - k + i];
    }
    cout << result << '\n';
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
