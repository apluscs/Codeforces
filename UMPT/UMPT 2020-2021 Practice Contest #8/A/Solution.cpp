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

int n, a, b, c;
struct Solution {
  int solve() {
    vector<int> dp(n + 1, -1);  // -1 means unpartionable
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      if (i >= a && dp[i - a] != -1) dp[i] = 1 + dp[i - a];
      if (i >= b && dp[i - b] != -1) dp[i] = max(dp[i], 1 + dp[i - b]);
      if (i >= c && dp[i - c] != -1) dp[i] = max(dp[i], 1 + dp[i - c]);
      // printf("i=%d, res=%d\n", i, dp[i]);
    }
    return dp[n];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b >> c;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}