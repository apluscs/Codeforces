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

int n;
vector<vector<int>> adj;

struct Solution {
  vector<bool> able;
  vector<int> size;
  void solve() {
    able.resize(n + 1);
    size.resize(n + 1, 1);
    dfs(1, -1);
    int res = 0;
    for (int i = 1; i < n - 1; ++i) {
      res += able[i];
    }
    cout << res << endl;
    for (int i = 1; i < n - 1; ++i) {
      if (able[i]) {
        cout << i << " " << n - 1 - i << endl;
      }
    }
  }

  int dfs(int rt, int par) {
    for (auto nei : adj[rt]) {
      if (nei == par) continue;
      size[rt] += dfs(nei, rt);
    }
    vector<bool> dp(n + 1);
    dp[0] = dp[n - size[rt]] = true;
    for (auto nei : adj[rt]) {
      if (nei == par) continue;
      for (int j = n; j >= 0; --j) {
        int x = j + size[nei];
        if (dp[j] && x <= n) {
          dp[x] = true;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      able[i] = able[i] || dp[i];
    }
    return size[rt];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  adj.clear();
  adj.resize(n + 1);
  for (int i = 1, x, y; i != n; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  Solution test;
  test.solve();
}