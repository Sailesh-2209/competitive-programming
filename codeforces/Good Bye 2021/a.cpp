#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> counts(101, 0);
    for (int i = 0; i < n; i++) {
        counts[abs(arr[i])]++;
    }
    int result = min(1, counts[0]);
    for (int i = 1; i < 101; i++) {
        result += min(2, counts[i]);
    }
    cout << result << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}
