/**
 * author        : sailboat22
 * timestamp    : 29 January 2022 (Saturday) 15:21 
**/

#include <bits/stdc++.h>

using namespace std;


void dfs(int curr, int color, vector<vector<int>> children, map<pair<int, int>, int>& hmap) {
    for (int child : children[curr]) {
        pair<int, int> key = make_pair(curr, child);
        if (hmap.find(key) == hmap.end()) {
            hmap[key] = hmap[make_pair(child, curr)] = color + 2;
            dfs(child, color ^ 1, children, hmap);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> degree(n, 0);
    vector<pair<int, int>> edges;
    vector<vector<int>> children(n);
    map<pair<int, int>, int> hmap;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        degree[u]++; degree[v]++;
        edges.push_back(make_pair(u, v));
        children[u].push_back(v);
        children[v].push_back(u);
    }
    if (*max_element(degree.begin(), degree.end()) > 2) {
        cout << "-1\n";
        return;
    }
    int start = min_element(degree.begin(), degree.end()) - degree.begin();
    dfs(start, 0, children, hmap);
    for (auto edge : edges) {
        cout << hmap[edge] << " ";
    }
    cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
