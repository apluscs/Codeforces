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
vector<int> nums;
struct Solution {
  vector<string> solve() {
    vector<bool> dp(101);
    dp[0] = dp[3] = dp[7] = true;
    for (int i = 4; i != 101; ++i) {
      dp[i] = dp[i] || dp[i - 3] || (i >= 7 && dp[i - 7]);
      // if (dp[i]) printf("i=%d ", i);
    }
    vector<string> res;
    // cout << dp[6] << endl;
    for (int num : nums) {
      res.push_back(dp[num] ? "YES" : "NO");
      // if (dp[num] || true) printf("i=%d ", num);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  Solution test;
  auto res = test.solve();
  for (auto r : res) {
    cout << r << endl;
  }
}