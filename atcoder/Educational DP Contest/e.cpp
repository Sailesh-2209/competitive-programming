#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e9 + 5;
const ll INF = 1e18L + 5;

void test_case() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        cin >> values[i];
    }
    int sum_values = 0;
    for (int value : values) 
        sum_values += value;
    vector<ll> dp(sum_values + 1, 0);
    // dp[i] represents the minimum total weight of items with total value exactly i
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum_values; j++) {
            if (j - values[i] >= 0) {
                dp[j - values[i]] = min(dp[i - values[i]])
            }
        }
    }
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
