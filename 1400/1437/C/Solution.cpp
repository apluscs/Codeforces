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
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;

int n;
vector<int> nums(n);

struct Solution {
  int solve() {
    sort(nums.begin(), nums.end());
    vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, 1e8));  // cost of doing x > 0 tasks in 0 seconds = impossible
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= n; ++i) {                                          // doing the i'th task
      for (int j = 1; j <= 2 * n; ++j) {                                    // at or before time j
        dp[i][j] = min(dp[i - 1][j - 1] + abs(nums[i] - j), dp[i][j - 1]);  // doing it now, doing it before
        // cout << dp[i][j] << " ";
      }
      // cout << endl;
    }
    return dp[n].back();
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    nums.resize(n + 1);
    REPN(i, n) {
      cin >> nums[i];
    }
    Solution test;
    cout << test.solve() << endl;
  }
}