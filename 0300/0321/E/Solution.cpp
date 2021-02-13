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

int n, k;
vector<vector<int>> pre, cost;
struct Solution {
  int solve() {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    fill(dp[0].begin(), dp[0].end(), 1e9);  // impossible to have people without a group
    dp[0][0] = 0;
    cost.resize(n + 1, vector<int>(n + 1));  // dp[i][j] = min cost for i groups made up of first i people
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        cost[i][j] = cost[i][j - 1] + pre[j][j] - pre[j][i - 1];
      }
    }
    // print(cost);
    for (int i = 1; i <= k; ++i) {  // i groups
      // printf("i=%d\n", i);
      int z = i;                      // first person in i'th group
      for (int j = i; j <= n; ++j) {  // using first j people
        // printf("z=%d\n", z);
        // cout << dp[i][j] << endl;
        // while (z < j && dp[i - 1][z] + cost[z + 1][j] <= dp[i - 1][z - 1] + cost[z][j]) z++;
        while (1) {
          bool upd = 0;
          int now = dp[i - 1][z - 1] + cost[z][j];
          for (int y = z + 1; y <= j; y++) {
            int nxt = dp[i - 1][y - 1] + cost[y][j];
            if (nxt <= now) {
              z = y, upd = 1;
              break;
            }
          }
          if (!upd) break;
        }
        dp[i][j] = dp[i - 1][z - 1] + cost[z][j];
      }
      // printf("\n");
    }
    // cout << endl;
    // print(dp);
    return dp[k][n];
  }
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }

  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  pre.resize(n + 1, vector<int>(n + 1));
  REPN(i, n) {
    REPN(j, n) {
      cin >> pre[i][j];
      if (j) pre[i][j] += pre[i][j - 1];  // prefix sums for each person
    }
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}
