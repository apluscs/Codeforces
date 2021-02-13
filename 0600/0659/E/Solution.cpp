#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;

struct Solution {
  vector<bool> vis;
  int nodes, edges;
  void solve() {
    vis.resize(n + 1);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        nodes = edges = 0;
        dfs(i);
        // printf("nodes= %d, edges= %d", nodes, edges);
        res += edges / 2 == nodes - 1;
      }
    }
    cout << res << endl;
  }
  void dfs(int v) {
    nodes++;
    edges += adj[v].size();
    // printf("v= %d, adj[v]= %d\n", v, adj[v].size());
    vis[v] = true;
    for (auto nei : adj[v]) {
      if (!vis[nei]) {
        dfs(nei);
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  adj.clear();
  adj.resize(n + 1);
  for (int i = 1, u, v; i != 1 + m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution test;
  test.solve();
}