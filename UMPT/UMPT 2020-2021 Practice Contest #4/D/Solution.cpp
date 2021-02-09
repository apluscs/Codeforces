#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
struct Solution {
  vector<bool> vis, req;
  bool solve() {
    if (!connected()) {
      return false;
    }
    if (cyclic()) {
      return false;
    }
    req.resize(n);
    for (int i = 0; i != n; ++i) req[i] = adj[i].size() >= 2;
    for (int i = 0; i != n; ++i) {
      int count = 0;
      if (!req[i]) continue;
      for (int j : adj[i]) {
        if (req[j]) count++;
      }
      if (count > 2) {
        // cout << i << endl;
        return false;
      }
    }
    return true;
  }
  bool cyclic() {
    vis.clear();
    vis.resize(n);
    return isCycle(0, -1);
  }
  bool isCycle(int curr, int par) {
    vis[curr] = true;
    for (auto i : adj[curr]) {
      if (!vis[i]) {
        if (isCycle(i, curr))
          return true;
      } else if (i != par)
        return true;
    }
    return false;
  }
  bool connected() {
    vis.resize(n);
    basic_dfs(0);
    return *min_element(vis.begin(), vis.end()) == 1;
  }
  void basic_dfs(int curr) {
    if (vis[curr]) return;
    vis[curr] = true;
    for (auto nei : adj[curr]) basic_dfs(nei);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (true) {
    cin >> n;
    if (!n) return 0;
    cin >> m;
    adj.clear();
    adj.resize(n);
    Solution test;
    int a, b;
    while (m--) {
      cin >> a >> b;
      a--, b--;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    auto res = test.solve();
    if (res)
      printf("Graph %d is a caterpillar.\n", t);
    else
      printf("Graph %d is not a caterpillar.\n", t);
    t++;
  }
}