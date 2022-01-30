/**
 * author       : sailboat22
 * timestamp    : 29 January 2022 (Saturday) 17:19 
**/

// go through all elements of array 
// find unique occuring instances of all numbers less than n
// go through missing elements, try to convert smallest array element to smallest missing element
// if it is not possible then output -1, if it is possible, it can be done in one step

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = 0;
    sort(a.begin(), a.end());
    vector<bool> seen(n + 1);
    deque<int> q;
    for (int num : a) {
        if (num <= n && !seen[num]) {
            seen[num] = true;
        } else {
            q.push_back(num);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (seen[i]) {
            continue;
        }
        int num = q.front();
        q.pop_front();
        if ((num % 2 == 0 && i < num / 2) || (num % 2 == 1 && i <= num / 2)) {
            result++;
        } else {
            cout << "-1\n";
            return;
        }
    }
    cout << result << '\n';
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
