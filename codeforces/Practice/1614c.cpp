/**
 * author       : sailboat22
 * timestamp    : 30 January 2022 (Sunday) 16:24 
**/

// https://codeforces.com/problemset/problem/1614/C

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    long long orr = 0;
    for (int i = 0; i < m; i++) {
        long long l, r, x;
        cin >> l >> r >> x;
        orr |= x;
    }
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        ans = (ans * 2) % mod;
    }
    ans = (ans * orr) % mod;
    cout << ans << '\n';
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
