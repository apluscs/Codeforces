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

int n, m, s1, t1, l1, s2, t2, l2;
vector<vector<int>> adj;
struct Solution {
  vector<vector<int>> dist;
  int solve() {
    dist.resize(n, vector<int>(n));
    REP(i, n) {
      get_dists(i);
    }
    int res = -1;
    REP(e, 2) {
      swap(s1, t1);  // get them on same side if originally on opposite sides
      REP(i, n) {
        REP(j, n) {
          int d1 = dist[s1][i] + dist[i][j] + dist[j][t1], d2 = dist[s2][i] + dist[i][j] + dist[j][t2];
          if (d1 > l1 || d2 > l2) continue;  // path(s) too long
          res = max(res, m - d1 - d2 + dist[i][j]);
          // printf("i=%d, j=%d, res=%d\n", i, j, res);
        }
      }
    }
    int d1 = dist[s1][t1], d2 = dist[s2][t2];
    if (d1 <= l1 && d2 <= l2) res = max(res, m - d1 - d2);  // no intersection
    return res;
  }
  void get_dists(int src) {  //goal is to make the last edge in the cycle = 2
    queue<int> que;
    vector<bool> vis(n);
    que.push(src);
    int step = 0;
    vis[src] = true;  // if has been added to queue
    while (!que.empty()) {
      for (int z = que.size(); z; --z) {
        auto curr = que.front();
        que.pop();
        dist[src][curr] = step;
        for (auto nei : adj[curr]) {
          if (vis[nei]) continue;
          que.push(nei);
          vis[nei] = true;
        }
      }
      step++;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.clear();
  adj.resize(n);  // n = "concert land"
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1--, t1--, l1, s2--, t2--, l2;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}
