#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> arr;
    int k = 1;
    while (k < n && (s[k] < s[k - 1] || (k > 1 && s[k] == s[k - 1])))
        k++;
    for (int i = 0; i < k; i++)
        cout << s[i];
    for (int i = k - 1; i >= 0; i--)
        cout << s[i];
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
}
