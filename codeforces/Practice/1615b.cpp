/**
 * author       : sailboat22
 * timestamp    : 29 January 2022 (Saturday) 19:03 
**/

#include <bits/stdc++.h>

using namespace std;

const int nax = 2e5 + 5;
vector<vector<int>> counts(nax, vector<int> (32, 0));

void calculate() {
    for (int i = 0; i < nax; i++) {
        int x = 31;
        while (--x >= 0) {
            int a = (i >> x) & 1;
            if (a == 1) {
                counts[i][x] = ((i == 0) ? 0 : counts[i - 1][x]) + 1;
            } else {
                counts[i][x] = ((i == 0) ? 0 : counts[i - 1][x]) + 0;
            }
        }
    }
}

void solve() {
    int l, r; cin >> l >> r;
    int res = 0;
    for (int i = 0; i < 32; i++) {
        res = max(res, counts[r][i] - counts[l - 1][i]);
    }
    int ans = r - l + 1 - res;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    calculate();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
