#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

ll x, y, ax, bx, ay, by, xs, ys, t;
struct Solution {
  vector<vector<ll>> pts, adj;
  int n;
  void solve() {
    precompute();
    n = pts.size();
    pts.push_back({xs, ys}); // start point
    adj.resize(n, vector<ll>(n));
    for (int i = 0; i != n; ++i) {
      for (int j = i + 1; j != n; ++j) { // distances
        adj[i][j] = adj[j][i] = adj[i][j - 1] + dist(j - 1, j);
      }
    }
    int res = 0;
    for (int i = 0; i != n; ++i) {  // try every pair of (start, end)
      for (int j = 0; j != n; ++j) {
        ll curr = dist(n, i) + dist(i, j);
        if (curr > t)
          continue;
        res = max(res, abs(i - j) + 1);
      }
    }
    cout << res << endl;
  }

  ll dist(int i, int j) { // for 2 pts
    return dist(pts[i][0], pts[i][1], pts[j][0], pts[j][1]);
  }
  ll dist(ll x1, ll y1, ll x2, ll y2) { return abs(x1 - x2) + abs(y1 - y2); }

  void precompute() { // get all the points
    while (x <= xs + t && y <= ys + t) {
      pts.push_back({x, y});
      // printf("x=%lld, y=%lld\n", x, y);
      x = ax * x + bx;
      y = ay * y + by;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> x >> y >> ax >> ay >> bx >> by >> xs >> ys >> t;
    Solution test;
    test.solve();
  }
}
