#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;

int n, m;
vector<vector<int>> adj;

struct Solution {
  vector<bool> vis;
  vector<int> deg, sub;
  void solve() {
    int res = 0;
    deg.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0, u, v; i != m; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }

    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      sub.clear();
      dfs(i);
      bool ok = true;
      for (auto x : sub) ok &= deg[x] == 2;
      res += ok;
    }
    cout << res << endl;
  }

  void dfs(int v) {
    vis[v] = true;
    sub.push_back(v);
    for (auto nei : adj[v]) {
      if (!vis[nei]) dfs(nei);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.clear();
  adj.resize(n + 1);
  Solution test;
  test.solve();
}