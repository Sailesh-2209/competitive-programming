/**
 * author       : sailboat22
 * timestamp    : 30 January 2022 (Sunday) 16:48 
**/

// https://codeforces.com/problemset/problem/1612/C

/*
- n = k * (k + 1) / 2
- if x > k * k 
-   we can print all lines, return 2 * k - 1
- else
-   binary search
*/


#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;
    long long n = k * (k + 1) / 2;
    if (x >= k * k) {
        long long ans = 2 * k - 1;
        cout << ans << '\n';
        return;
    } else {
        if (x <= n) {
            long long lo = 1, hi = k;
            while (lo <= hi) {
                long long mid = lo + (hi - lo) / 2;
                long long num = mid * (mid + 1) / 2;
                if (x > num) lo = mid + 1;
                else hi = mid - 1;
            }
            cout << lo << '\n';
        } else {
            long long total = k * (k - 1) / 2;
            long long ans = k;
            x -= n;
            long long lo = 1, hi = k - 1;
            while (lo <= hi) {
                long long mid = lo + (hi - lo) / 2;
                long long lines = k - 1 - mid;
                long long num = total - (lines * (lines + 1) / 2);
                if (x > num) lo = mid + 1;
                else hi = mid - 1;
            }
            ans += lo;
            cout << ans << '\n';
        }
    }
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
