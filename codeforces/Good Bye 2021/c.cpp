/*
 * author: sailboat22
 * created: 01/12/2022 11:45:56
*/

#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int ans = n - 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if ((a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i))
                    count++;
            }
            ans = min(ans, count);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

