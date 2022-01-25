#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> stones(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) cin >> stones[i];
    for (int i = 1; i < n; i++) {
        int a = abs(stones[i] - stones[i - 1]) + dp[i - 1];
        int b = (i > 1) ? abs(stones[i] - stones[i - 2]) + dp[i - 2] : INT_MAX;
        dp[i] = min(a, b);
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
