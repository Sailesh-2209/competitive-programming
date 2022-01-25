#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(n, 0);
    for (auto& num : arr) cin >> num;
    for (int i = 0; i < n; i++) {
        vector<int> vals;
        for (int j = 1
        ; j <= k && i - j >= 0; j++) {
            vals.push_back(abs(arr[i - j] - arr[i]) + dp[i - j]);
        }
        dp[i] = vals.size() > 0 ? *min_element(vals.begin(), vals.end()) : 0;
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("solution.txt", "w", stdout);
    #endif
    int t = 1;
    while (t--) {
        test_case();
    }
    return 0;
}
