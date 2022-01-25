#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case() {
    int n, w;
    cin >> n >> w;
    vector<ll> dp(w + 1, 0);
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        for (int j = w - weight; j >= 0; j--) {
            dp[j + weight] = max(dp[j] + value, dp[j + weight]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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
