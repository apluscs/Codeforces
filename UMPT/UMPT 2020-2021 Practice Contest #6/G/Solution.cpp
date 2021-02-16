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

int n;
vector<int> nums;
pair<int, int> ST[100001][20];

struct Solution {
  ll solve() {
    build_ST();
    ll res = 0;
    vector<ll> dp(n);
    // for (int j = 0; j != 4; ++j) {
    //   for (int i = 0; i <= n; ++i) {
    //     // printf("i=%d, j=%d, max=%d\n", i, j, ST[i][j].first);
    //     printf("%d ", ST[i][j].second);
    //   }
    //   printf("\n");
    // }

    for (int i = n - 2; i >= 0; --i) {
      int m = query(i + 1, nums[i]);
      // printf("s=%d, e=%d, m=%d\n", i + 1, nums[i], m);
      dp[i] = dp[m] + n - 1 - i - (nums[i] - m);  // dp[m] = cost for m+1...n-1 from m, add 1 for all but subtract the cost (1) from m to nums[i]
      res += dp[i];
    }
    return res;
  }
  void build_ST() {
    for (int i = 0; i < n; ++i) ST[i][0] = {nums[i], i};
    for (int j = 1; j != 18; ++j)
      for (int i = 0; i + (1 << j) <= n; ++i)  // will this be used?
        ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
  }
  int query(int s, int e) {                                // find argmax nums[i] for this range
    int x = floor(log2(e - s + 1));                        // log2(range)
    return max(ST[s][x], ST[e - (1 << x) + 1][x]).second;  // want the actual index
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  REP(i, n - 1) {
    cin >> nums[i];
    nums[i]--;
  }
  nums[n - 1] = n - 1;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}