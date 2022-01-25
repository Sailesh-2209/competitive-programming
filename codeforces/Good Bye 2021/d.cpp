/**
 *  author:  sailboat22
 *  created: 01/12/2022 18:40:16
**/

#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) arr[i] -= x;
    vector<int> pre(n, 0);
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + arr[i - 1];
    int max_u = 0;
    int ans = n;
    for (int i = 1; i < n; i++) {
        if (pre[i] < max_u) {
            max_u = pre[i];
            ans--;
            i++;
        } else {
            max_u = max(max_u, pre[i - 1]);
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

