#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case() {
    int n;
    cin >> n;
    vector<double> dp (n + 1, 0);
    dp[0] = 1;
    for (int coin = 0; coin < n; coin++) {
        double p_head;
        cin >> p_head;
        for (int i = coin + 1; i >= 0; i--) {
            dp[i] = (i == 0 ? 0 : dp[i - 1] * p_head) + (dp[i] * (1 - p_head));
        }
    }
    double answer = 0;
    for (int heads = 0; heads <= n; heads++) {
        int tails = n - heads;
        if (heads > tails) answer += dp[heads];
    }
    cout << setprecision(10) << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
