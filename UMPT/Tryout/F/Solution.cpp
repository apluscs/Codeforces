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
  int solve() {
    unordered_map<int, long> dp;
    for (int num : nums) {
      // cout << num << endl;
      auto prev = dp;
      for (auto& p : prev) {
        int g = p.first, f = p.second, x = __gcd(num, g);
        dp[x] += f;
        dp[x] %= mod;
      }
      dp[num]++;  // just itself
    }
    return dp[1];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  // cout << "hi" << endl;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}