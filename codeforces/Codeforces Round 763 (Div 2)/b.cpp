/**
 *  author:  sailboat22
 *  created: 01/13/2022 12:35:04
**/

#include <iostream>
#include <set>
#include <utility>
#include <deque>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    set<pair<int, int>> numset;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        numset.insert(make_pair(a, b));
    }
    deque<pair<int, int>> q;
    q.push_back(make_pair(1, n));
    while (!q.empty()) {
        pair<int, int> range = q.front();
        q.pop_front();
        bool ans = false;
        if (range.first == range.second) {
            cout << range.first << " " << range.second << " " << range.first << "\n";
            ans = true;
            continue;
        }
        if (ans)
            continue;
        for (int i = range.first + 1; i < range.second; i++) {
            pair<int, int> first = make_pair(range.first, i - 1);
            pair<int, int> second = make_pair(i + 1, range.second);
            if (numset.find(first) != numset.end() && numset.find(second) != numset.end()) {
                cout << range.first << " " << range.second << " " << i << "\n";
                q.push_back(first);
                q.push_back(second);
                ans = true;
            }
            if (ans)
                continue;
        }
        if (ans)
            continue;
        pair<int, int> first = make_pair(range.first + 1, range.second);
        pair<int, int> last = make_pair(range.first, range.second - 1);
        if (ans)
            continue;
        if (numset.find(first) != numset.end()) {
            cout << range.first << " " << range.second << " " << range.first << "\n";
            q.push_back(first);
        } else {
            cout << range.first << " " << range.second << " " << range.second << "\n";
            q.push_back(last);
        }
    }
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

