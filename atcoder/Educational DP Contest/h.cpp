#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void test_case() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char> ());
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i].push_back(c);
        }
    }
    vector<vector<int>> dp(m, vector<int> (n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '.') {
                int a = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                int b = (j - 1 >= 0) ? dp[i][j - 1] : 0;
                dp[i][j] = (a + b) % mod;
            }
        }
    }
    cout << dp[m - 1][n - 1] << '\n';
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
