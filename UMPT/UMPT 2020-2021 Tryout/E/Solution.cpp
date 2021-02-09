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

int n, m, Q;
vector<string> grid, temp;
vector<pair<int, int>> qs;
struct Solution {
  int solve() {
    int res = n * m;
    for (int mask = 0; mask != (1 << Q); ++mask) {
      // for (int mask = 5; mask != (6); ++mask) {
      for (int t = 0; t != Q; ++t) {
        int b = mask & (1 << t), i = qs[t].first, j = qs[t].second;
        grid[i][j] = b ? '1' : '0';
      }
      temp = grid;
      res = min(res, count());
    }
    return res;
  }
  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int count() {
    int res = 0;
    for (int i = 0; i != n; i++)
      for (int j = 0; j != m; j++) {
        // printf("**i=%d, j=%d\n", i, j);
        if (temp[i][j] == '.') continue;  // already visited
        res++;
        dfs(i, j);  // flood as visited
      }
    return res;
  }
  void dfs(int i, int j) {
    char c = temp[i][j];
    temp[i][j] = '.';
    // printf("i=%d, j=%d, c=%c\n", i, j, c);
    for (auto d : dir) {
      int ni = i + d[0], nj = j + d[1];
      if (out(ni, nj) || c != temp[ni][nj]) continue;
      dfs(ni, nj);
    }
  }
  bool out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  grid.clear();
  grid.resize(n), Q = 0;
  REP(i, n) {
    cin >> grid[i];
    REP(j, m) {
      if (grid[i][j] == '?') qs.push_back({i, j});
    }
  }
  Q = qs.size();
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}