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

using namespace std;
const int mod = 1e9 + 7;

int n, m, ti, tj, hi, hj;  // target, hole
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> grid;
struct Solution {
  vector<int> res;
  vector<int> solve() {
    dfs(-3);
    return res;
  }
  bool dfs(int par) {                       // car moved before this
    if (hi == ti && hj == tj) return true;  // uncovered the item
    for (auto d : dir) {
      int i = hi + d[0], j = hj + d[1], ni = i + d[0], nj = j + d[1];  // two points of the car
      if (out(i, j) || out(ni, nj) || grid[i][j] != grid[ni][nj] || grid[i][j] == par) continue;
      swap(grid[ni][nj], grid[hi][hj]);
      hi = ni, hj = nj;
      res.pb(grid[i][j]);
      if (dfs(grid[i][j])) return true;
      res.pop_back();
      swap(grid[ni][nj], grid[hi][hj]);
      hi = i - d[0], hj = j - d[1];
    }
    return false;
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  grid.clear();
  grid.resize(n, vector<int>(m));
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == -1) {
        hi = i, hj = j;
      }
    }
  }
  cin >> ti >> tj;
  ti--, tj--;
  Solution test;
  auto res = test.solve();
  if (res.empty())
    cout << "impossible" << endl;
  else {
    for (auto r : res) cout << r << " ";
    cout << endl;
  }
}