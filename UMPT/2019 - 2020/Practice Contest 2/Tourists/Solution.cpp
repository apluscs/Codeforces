#include <math.h> /* log2 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<vector<int>> adj;

class Solution {
 public:
  vector<int> depth;
  vector<vector<int>> par;
  int D;
  ll solve() {
    D = ceil(log2(n));
    par.resize(n, vector<int>(D + 1, -1));
    depth.resize(n, -1);
    prep_depths();
    // for (auto d : depth) cout << d << " ";
    // cout << endl;
    for (int j = 1; j <= D; ++j) {  // level of parent
      for (int i = 0; i != n; ++i) {
        if (par[i][j - 1] == -1) continue;
        par[i][j] = par[par[i][j - 1]][j - 1];
      }
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + i; j <= n; j += i) {
        res += dist(i - 1, j - 1);  // value x = node x-1
      }
    }
    return res;
  }

  int dist(int i, int j) {
    int c = lca(i, j), res = depth[i] - 2 * depth[c] + depth[j] + 1;
    // cout << "dist " << (1 + i) << "," << (1 + j) << "=" << res << endl;
    return res;
  }
  int walkup(int i, int k) {
    // cout << "walking " << i << " up " << k << " steps...";
    while (k) {
      int x = k & -k, j = log2(x);  // index of rightmost set bit
      i = par[i][j];
      k ^= x;
    }
    // cout << "i is now " << i << endl;
    return i;
  }

  int lca(int i, int j) {
    if (depth[i] > depth[j])
      i = walkup(i, depth[i] - depth[j]);  // i deeper than j
    else if (depth[i] < depth[j])
      j = walkup(j, depth[j] - depth[i]);  // j deeper than i
    if (i == j) return i;
    for (int d = D; d >= 0; --d) {
      if (par[i][d] != par[j][d]) {
        i = par[i][d];
        j = par[j][d];
      }
    }
    return par[i][0];
  }
  void prep_depths() {
    queue<int> que;
    int d = 0;
    que.push(0);
    while (!que.empty()) {
      for (int s = que.size(); s; --s) {
        int curr = que.front();
        que.pop();
        depth[curr] = d;
        for (auto v : adj[curr]) {
          if (depth[v] != -1) continue;  // already visited before
          par[v][0] = curr;
          que.push(v);
        }
      }
      d++;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  adj.resize(n);
  for (int i = 1; i != n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);  // 0base everything
    adj[b].push_back(a);
  }
  Solution test;
  cout << test.solve() << endl;
}