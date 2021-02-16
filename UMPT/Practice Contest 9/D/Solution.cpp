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

int n, m, K, grid[500][500], dp[500][500][11];
struct Solution {
  string solve() {
    int res = INT_MAX;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i != n; ++i) {
      dp[i][0][0] = grid[i][0];  // -1 means impossible
    }
    for (int j = 1; j != m; ++j) {  // go col by col
      for (int i = 0; i != n; ++i) {
        if (out(i, j)) continue;
        int x = grid[i][j];
        for (int k = 0; k <= K; ++k) {  // this many passes
          int best = INT_MAX, pk = k - is_pass(i, j);
          if (pk == -1) continue;  // leave as -1, means this is a pass and we need -1 passes from before
          for (int di = -1; di <= 1; ++di) {
            int ni = i + di, p = out(ni, j - 1) ? -1 : dp[ni][j - 1][pk];
            // printf("i=%d, j=%d, p=%d, ni=%d\n", i, j, p, ni);
            if (p != -1) best = min(best, p);
          }
          dp[i][j][k] = best == INT_MAX ? -1 : best + x;
        }
      }
    }
    // for (int k = 0; k <= K; ++k) {  // this many passes
    //   printf("k=%d\n", k);
    //   REP(i, n) {
    //     REP(j, m)
    //     printf("%d ", dp[i][j][k]);
    //     printf("\n");
    //   }
    // }
    for (int i = 0; i != n; ++i) {
      if (dp[i][m - 1][K] != -1) res = min(res, dp[i][m - 1][K]);
    }
    return res == INT_MAX ? "impossible" : to_string(res);
  }
  bool is_pass(int i, int j) {
    return !out(i - 1, j) && !out(i + 1, j) && !out(i, j - 1) && !out(i, j + 1) && grid[i][j] < grid[i - 1][j] && grid[i][j] < grid[i + 1][j] && grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1];
  }
  bool out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> K;
  REP(i, n)
  REP(j, m)
  cin >> grid[i][j];
  Solution test;
  cout << test.solve() << endl;
}