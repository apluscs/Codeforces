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
  vector<int> color;
  vector<int> counts;
  bool ok = true;
  void solve() {
    color.resize(n + 1);
    counts.resize(3);
    for (int i = 1; i <= n; ++i) {
      if (color[i]) continue;
      dfs(i, 1);
    }
    if (!ok) {
      cout << "-1" << endl;
      return;
    }
    for (int c = 1; c != 3; ++c) {
      cout << counts[c] << endl;
      for (int i = 1; i <= n; ++i) {
        if (color[i] == c) cout << to_string(i) << " ";
      }
      cout << endl;
    }
  }

  void dfs(int v, int clr) {
    if (!ok) return;
    color[v] = clr;
    counts[clr]++;
    for (auto nei : adj[v]) {
      if (color[nei] == clr) {
        ok = false;
        return;
      }
      if (!color[nei]) dfs(nei, 3 - clr);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0, u, v; i != m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution test;
  test.solve();
}