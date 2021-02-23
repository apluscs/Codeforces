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
#include <stack>
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

int n, m, cals[101], dp[101][200001];
struct Solution {
  int solve() {
    memset(dp, -1, sizeof(dp));
    return dfs(0, m, m);
  }
  int dfs(int i, int j, int prev) {  // j = current capacity
    if (i >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = max(dfs(i + 1, prev, 0), max(dfs(i + 1, j * 2 / 3, j) + min(cals[i], j), dfs(i + 2, m, 0)));
    // printf("i=%d, j=%d, res=%d\n", i, j, dp[i][j]);
    return dp[i][j];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, n)
  cin >> cals[i];
  Solution test;
  cout << test.solve() << endl;
}