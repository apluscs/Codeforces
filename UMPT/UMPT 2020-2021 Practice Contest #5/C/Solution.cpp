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

int n;
vector<ll> nums;
struct Solution {
  vector<vector<int>> groups, adj;  // indices into nums
  int bad, step, res = 1e6;
  unordered_set<ll> vis;
  int solve() {
    groups.clear();
    groups.resize(64);
    adj.clear();
    adj.resize(n);
    REP(i, n) {
      for (int j = 0; j != 64; ++j) {
        if (((1ULL << j) & nums[i]) != 0)
          groups[j].pb(i);
        else
          continue;
        if (groups[j].size() == 3) return 3;
        if (groups[j].size() == 2) {  // will be used if everything <= 2
          adj[groups[j][0]].pb(groups[j][1]);
          adj[groups[j][1]].pb(groups[j][0]);
        }
      }
    }
    for (int i = 0; i != n; ++i) {
      for (auto j : adj[i]) {  // testing cycle from i to j, second to last stop is j
        if (i > j) continue;
        res = min(res, bfs(i, j));
      }
    }
    return res == 1000000 ? -1 : res;
  }
  int bfs(int s, int t) {
    // cout << "bfs" << endl;
    queue<int> que;
    vector<bool> vis(n);
    que.push(s);
    vis[s] = true;
    int res = 1;
    while (!que.empty()) {
      for (int z = que.size(); z; --z) {
        auto curr = que.front();
        if (curr == t)
          return res;
        que.pop();
        for (auto nei : adj[curr]) {
          if (nei == t && curr == s) continue;
          if (vis[nei]) continue;
          vis[nei] = true;
          que.push(nei);
        }
      }
      res++;
    }
    return 1e6;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}