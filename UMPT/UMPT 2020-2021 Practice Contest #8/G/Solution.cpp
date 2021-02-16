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

int n, nums[501], dp[501][501];
struct Solution {
  int solve() {
    memset(dp, 0, sizeof(dp));
    REP(l, n) {
      for (int i = 0, j = i + l; j < n; ++i, ++j) {
        if (i == j) {
          dp[i][j] = 1;
          continue;
        }
        dp[i][j] = 1 + dp[i + 1][j];        // remove nums[i] alone
        for (int k = i + 1; k <= j; ++k) {  // the one nums[i] matches with
          if (nums[i] != nums[k]) continue;
          int x = dp[i + 1][k - 1] + dp[k + 1][j];
          dp[i][j] = min(dp[i][j], x + (k == i + 1));
        }
      }
    }
    // REP(i, n) {
    //   REP(j, n)
    //   cout << dp[i][j] << " ";
    //   cout << endl;
    // }
    return dp[0][n - 1];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, n)
  cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
}