#include <assert.h>
#include <math.h>

#include <algorithm>
#include <bitset>
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

int n, m, k;
vector<vector<int>> adj;
struct Solution {
  int solve() {
    vector<int> dp(1 << n, 41);  // 1 for each state
    dp[1] = 0;                   // 0 edges to just
    int req = 0, res = 41;
    for (int i = 1; i <= k + 1; ++i) {  // all nodes we must cover
      req |= (1 << i);
    }
    for (int i = 1; i != dp.size(); ++i) {
      for (int j = 0; j != n; ++j) {
        if ((i & (1 << j)) == 0) continue;  // j not in i
        for (int k : adj[j]) {
          dp[(1 << k) | i] = min(dp[(1 << k) | i], dp[i] + 1);  // use edge (j,k)
        }
      }
      if ((req & i) == req) {
        res = min(res, dp[i]);
      }
    }
    // for (int i = 1; i != dp.size(); ++i) {
    //   bitset<7> bits(i);
    //   if (dp[i] == 41) continue;
    //   // printf("i=%s, dp[i]=%d\n", bits.to_string().c_str(), dp[i]);
    // }
    // print(adj);
    return res;
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
  cin >> n >> m >> k;
  adj.clear(), adj.resize(n);
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    a--, b--;
    adj[b].push_back(a);  // reverse directions to go from node 0 to the rest; otherwise would have to set dp[i] = 0 for all i, instead of just for 0
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}
