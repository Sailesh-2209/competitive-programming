#include <iostream>
#include <vector>

using namespace std;

int ask(int i) {
    int x;
    cout << "? " << i + 1 << endl;
    cin >> x;
    return x - 1;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            int a = ask(i);
            int b = ask(i);
            vector<int> q;
            q.push_back(b);
            while (b != a) {
                b = ask(i);
                q.push_back(b);
            }
            for (int j = 0; j < q.size(); j++) {
                p[q[j]] = q[(j + 1) % q.size()];
            }
        }
    }
    cout << "! ";
    for (int i : p)
        cout << i + 1 << " ";
    cout << endl;
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
