#include <bits/stdc++.h>

using namespace std;

void test_case() {
    string a, b;
    cin >> a >> b;
    int alen = a.size();
    int blen = b.size();
    vector<vector<int>> dp(alen + 1, vector<int> (blen + 1, 0));
    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = alen, j = blen;
    string ans = "";
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--; j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
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
