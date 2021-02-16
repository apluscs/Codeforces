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

int n, m;
vector<string> grid;
struct Solution {
  int solve() {
    REP(i, n) {
      REP(j, m)
      dfs(i, j);
    }
    int res = 0;
    for (string& s : grid) {
      for (char c : s) res += c == 'B';
    }
    // print(grid);
    return res;
  }
  bool dfs(int i, int j) {
    if (out(i, j)) return true;
    char c = grid[i][j];
    if (c == 'B') return false;  // out or visited
    if (c == 'G') return true;  // good
    grid[i][j] = 'B';
    bool res;
    if (c == 'N')
      res = dfs(i - 1, j);
    else if (c == 'S')
      res = dfs(i + 1, j);
    else if (c == 'E')
      res = dfs(i, j + 1);
    else if (c == 'W')
      res = dfs(i, j - 1);
    grid[i][j] = res ? 'G' : 'B';
    return res;
  }
  bool out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
  void print(vector<string>& nums) {
    for (auto num : nums) cout << num << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  grid.resize(n);
  REP(i, n) {
    cin >> grid[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}