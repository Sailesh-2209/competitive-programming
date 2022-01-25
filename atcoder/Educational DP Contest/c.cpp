#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        vector<int> acts (3);
        for (int j = 0; j < 3; j++) cin >> acts[j];
        arr.push_back(acts);
    }
    vector<vector<int>> dp(n, vector<int> (3, 0));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
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
