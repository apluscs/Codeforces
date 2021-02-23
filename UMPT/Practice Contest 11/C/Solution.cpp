#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n, m;
vector<string> grid;
bool vis[50][50];
struct Solution {
  string solve() {
    memset(vis, 0, sizeof(vis));
    REP(i, n) {
      REP(j, m) {
        if (!vis[i][j] && isCycle(i, j, -1, -1)) return "Yes";
      }
    }
    return "No";
  }
  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool isCycle(int i, int j, int pi, int pj) {
    vis[i][j] = true;
    // printf("i=%d, j=%d\n", i, j);
    for (auto d : dir) {
      int ni = i + d[0], nj = j + d[1];
      if (out(ni, nj) || grid[ni][nj] != grid[i][j]) continue;  // valid neighbor
      // printf("ni=%d, nj=%d,i=%d, j=%d\n", ni, nj, i, j);
      if (!vis[ni][nj]) {
        if (isCycle(ni, nj, i, j)) {
          // printf("ni=%d, nj=%d\n", ni, nj);
          return true;
        }
      } else if (ni != pi || nj != pj) {
        // printf("**ni=%d, nj=%d,i=%d, j=%d\n", ni, nj, i, j);
        return true;
      }
    }
    return false;
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  Solution test;
  grid.resize(n);
  REP(i, n)
  cin >> grid[i];
  cout << test.solve() << endl;
}