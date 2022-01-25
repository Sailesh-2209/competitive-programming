#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
vector<int> edges[nax];
int dist[nax];
int indegree[nax];
bool visited[nax];

void dfs(int node) {
    visited[node] = true;
    for (int next : edges[node]) {
        dist[next] = max(dist[next], dist[node] + 1);
        --indegree[next];
        if (indegree[next] == 0)
            dfs(next);
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        indegree[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && indegree[i] == 0) {
            dfs(i);
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dist[i]);
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("solution.txt", "w", stdout);
    #endif
    int t = 1;
    while (t--) {
        test_case();
    }
    return 0;
}
