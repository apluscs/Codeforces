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

int n, m, K;
string key;
vector<string> grid;
struct Solution {
  int dp[100][100][50];
  int solve() {
    memset(dp, -1, sizeof(dp));
    // print(grid);
    dfs(0, 0, 0);
    // for (int i = 0; i != n; ++i) {
    //   for (int j = 0; j != m; ++j) {
    //     for (int k = 0; k <= K; ++k) {
    //       printf("i=%d, j=%d, k=%d, res=%d %d\n", i, j, k, dp[i][j][k]);
    //     }
    //   }
    // }
    return dfs(0, 0, 0);
  }
  int dfs(int i, int j, int k) {
    // printf("i=%d, j=%d, k=%d\n", i, j, k);
    if (out(i, j)) return 1e6;                              // should never be the answer
    if (i == n - 1 && j == m - 1) return grid[i][j] - '0';  // final value
    if (dp[i][j][k] != -1) return dp[i][j][k];
    int x = grid[i][j] - '0';
    // printf("i=%d, j=%d, k=%d, x=%d\n", i, j, k, x);
    int res = min(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;  // dont' use hop
    if (k == K) return dp[i][j][k] = res;
    int h = key[k] - '0';
    res = min(res, dfs(i + h + 1, j, k + 1) + x);
    res = min(res, dfs(i, j + h + 1, k + 1) + x);
    return dp[i][j][k] = res;
  }
  void print(vector<string>& nums) {
    for (auto num : nums) cout << num << endl;
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> n >> key;
  K = key.length();
  grid.clear(), grid.resize(n);
  for (int i = 0; i != n; ++i) {
    cin >> grid[n - i - 1];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}