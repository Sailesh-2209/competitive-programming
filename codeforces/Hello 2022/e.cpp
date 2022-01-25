#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v[3] << endl;
    v = new vector<int>;
    cout << v[3] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
}
