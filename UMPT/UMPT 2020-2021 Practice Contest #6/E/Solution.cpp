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

int n, m;
vector<vector<int>> oa, ob;
vector<vector<int>> ques;
struct Solution {
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }

  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
  vector<int> dp;
  vector<int> solve() {
    sort(oa.begin(), oa.end());
    // print(oa);
    dp.resize(1e5 + 1);
    int oi = 0;
    for (int j = 0; j <= 1e5; ++j) {  // dp[j] = farthest you can get with an interval starting <= j
      while (true) {
        if (oi + 1 < n && oa[oi + 1][1] < j) {
          oi++;  // now ends >= j
        } else
          break;
      }
      if (oa[oi][0] > j) continue;
      while (true)
        if (oi < n - 1 && oa[oi + 1][0] <= j) {
          oi++;
        } else
          break;  // find the farthest you can go
      if (oa[oi][1] < j) continue;
      dp[j] = oa[oi][1];
      printf("oi=%d,j=%d,dp[j]=%d\n ", oi, j, dp[j]);
    }
    vector<int> res;  // distances,
    for (auto que : ques) {
      res.pb(help(que[0], que[1]));
    }
    return res;
  }
  int help(int low, int high) {
    int i = low, res = 0;
    while (i < high) {
      int curr = dp[i];
      if (!curr || curr == i) return -1;  // cannot move
      i = curr;
      // printf("i=%d\n", i);
      res++;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int l, r;
  oa.clear();
  REP(i, n) {
    cin >> l >> r;
    oa.pb({l, r});
  }
  Solution test;
  ques.clear();
  REP(i, m) {
    cin >> l >> r;
    ques.pb({l, r});
  }
  auto res = test.solve();
  REP(i, m) {
    cout << res[i] << endl;
  }
}