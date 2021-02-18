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

int n;
vector<string> ss;
vector<int> nums;
struct Solution {
  ll solve() {
    vector<vector<ll>> dp(n, vector<ll>(2));  // dp[i][0] = min cost if ss[i] is not reversed, [i][1] = min cost if ss[i] is reversed
    dp[0][1] = nums[0];                       // cost to reverse first string
    // ll IMP = 1e19;
    for (int i = 1; i != n; ++i) {
      string &a = ss[i - 1], b = a, c = ss[i];  // a non reversed prev, b = reversed prev
      reverse(b.begin(), b.end());
      reverse(c.begin(), c.end());  // c = reversed curr
      dp[i][0] = LLONG_MAX;
      if (ss[i] >= a) dp[i][0] = dp[i - 1][0];
      if (ss[i] >= b) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
      dp[i][1] = LLONG_MAX;
      if (c >= a && dp[i - 1][0] != LLONG_MAX) dp[i][1] = nums[i] + dp[i - 1][0];
      if (c >= b && dp[i - 1][1] != LLONG_MAX) dp[i][1] = min(dp[i][1], nums[i] + dp[i - 1][1]);
    }
    // print(dp);
    return min(dp[n - 1][0], dp[n - 1][1]);
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
  cin >> n;
  nums.resize(n);
  ss.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  REP(i, n) {
    cin >> ss[i];
  }
  Solution test;
  auto res = test.solve();
  cout << (res == LLONG_MAX ? -1 : res) << endl;
}
