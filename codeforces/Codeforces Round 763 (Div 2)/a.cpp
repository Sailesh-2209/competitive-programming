/**
 *  author:  sailboat22
 *  created: 01/13/2022 11:48:17
**/

#include <iostream>

using namespace std;

void test_case() {
    int m, n, rb, cb, rd, cd;
    cin >> m >> n >> rb >> cb >> rd >> cd;
    int val1 = (cb <= cd) ? cd - cb : 2 * n - cb - cd;
    int val2 = (rb <= rd) ? rd - rb : 2 * m - rb - rd;
    cout << min(val1, val2) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

