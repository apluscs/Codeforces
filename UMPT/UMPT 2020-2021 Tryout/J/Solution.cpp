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
const int mod = 1e9 + 7;

int n, m;
string s, tar = "michigan";
struct Solution {
  int solve() {
    n = s.length(), m = tar.length();
    vector<vector<ll>> dp(m, vector<ll>(n));
    for (int i = 0; i != m; ++i) {
      for (int j = 0; j != n; ++j) {
        if (j) dp[i][j] = dp[i][j - 1];
        ll p = i && j ? dp[i - 1][j - 1] : !i;  // how many ways to form everything before i using s[:j)
        if (tar[i] == s[j]) dp[i][j] = (p + dp[i][j]) % mod;
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}