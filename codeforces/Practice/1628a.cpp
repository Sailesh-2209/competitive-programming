/**
 * author       : sailboat22
 * timestamp    : 28 January 2022 (Friday) 18:42 
**/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int i = 0;
    vector<int> result;
    while (i < n) {
        int mex = 0;
        while (cnt[mex] > 0) {
            mex++;
        }
        int greedy_mex = 0;
        vector<bool> v(mex);
        while (i < n) {
            if (a[i] < mex && !v[a[i]]) {
                v[a[i]] = true;
                greedy_mex++;
            }
            cnt[a[i]]--; i++;
            if (greedy_mex == mex) {
                break;
            }
        }
        result.push_back(greedy_mex);
    }
    int sz = result.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
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
