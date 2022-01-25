/**
 *  author:  sailboat22
 *  created: 01/13/2022 16:01:31
**/

#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> arr, int x) {
    vector<int> copy(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = n - 1; i >= 2; i--) {
        if (copy[i] < x)
            return false;
        int min_val = min(arr[i], copy[i] - x) / 3;
        copy[i - 1] += min_val;
        copy[i - 2] += 2 * min_val;
    }
    return copy[0] >= x && copy[1] >= x;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(arr, mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

