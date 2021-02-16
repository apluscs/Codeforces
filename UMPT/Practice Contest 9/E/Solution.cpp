#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

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

int n, m, K, grid[71][71], dp[71][71][36][70];  // dp[i][j][t][r] = max sum if using everything <= (i,j) and you took <= t elems from this row and you achieved remainder r
struct Solution {
  int solve() {
    int res = 0;
    memset(dp, -1, sizeof(dp));  // -1 reflects cannot achieve
    dp[0][m][m / 2][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        int x = grid[i][j];
        for (int r = 0; r != K; ++r) {              // remainder
          dp[i][j][0][r] = dp[i - 1][m][m / 2][r];  // taking 0 elems --> all from row above
          // if (dp[i][j][0][r] != -1) cout << i << "," << j << "," << 0 << "," << r << "," << dp[i][j][0][r] << endl;
        }
        if (j == 0) continue;                                              // can't take anymore elems
        for (int t = 1; t <= m / 2; ++t) {                                 // how many did you take
          for (int r = 0; r != K; ++r) {                                   // remainder
            dp[i][j][t][r] = max(dp[i][j - 1][t][r], dp[i][j][t - 1][r]);  // don't use this elem: either use <= t without elem j OR copy from elem j but using t-1
            int y = ((r - x) % K + K) % K; 
            int p = dp[i][j - 1][t - 1][y];
            if (p != -1) dp[i][j][t][r] = max(dp[i][j][t][r], p + x);
            // if (dp[i][j][t][r] != -1) cout << i << "," << j << "," << t << "," << r << "," << dp[i][j][t][r] << endl;
          }
        }
        res = max(res, dp[i][j][m / 2][0]);
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> K;
  FORN(i, 1, n) {
    FORN(j, 1, m) {
      cin >> grid[i][j];
    }
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}