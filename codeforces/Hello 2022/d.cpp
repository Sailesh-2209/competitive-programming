#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void test_case() {
    int n;
    cin >> n;
    vector<vector<ll>> cost_matrix(2 * n, vector<ll> (2 * n));
    ll cost = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> cost_matrix[i][j];
            if (i >= n && j >= n)
                cost += cost_matrix[i][j];
        }
    }
    ll add_cost = 1e9 + 1;
    add_cost = min(add_cost, cost_matrix[0][n]);
    add_cost = min(add_cost, cost_matrix[0][2 * n - 1]);
    add_cost = min(add_cost, cost_matrix[n - 1][n]);
    add_cost = min(add_cost, cost_matrix[n - 1][2 * n - 1]);
    add_cost = min(add_cost, cost_matrix[n][0]);
    add_cost = min(add_cost, cost_matrix[2 * n - 1][0]);
    add_cost = min(add_cost, cost_matrix[n][n - 1]);
    add_cost = min(add_cost, cost_matrix[2 * n - 1][n - 1]);
    cout << add_cost + cost << "\n";
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
