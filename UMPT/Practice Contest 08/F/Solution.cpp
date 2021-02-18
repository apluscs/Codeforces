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

int n, m, K, nums[19], adj[19][19];
ll dp[1 << 19][19];
struct Solution {
  ll solve() {
    memset(dp, -1, sizeof(dp));
    return dfs(1, 0, 0);
  }
  ll dfs(int s, int last, int count) {
    if (count == m) return 0;  // nothing else to add
    if (dp[s][last] != -1) return dp[s][last];
    FORN(i, 1, n) {
      if (s & (1 << i)) continue;  // i is already in s
      dp[s][last] = max(dp[s][last], dfs(s + (1 << i), i, count + 1) + nums[i] + adj[last][i]);
    }
    return dp[s][last];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> K;
  FORN(i, 1, n)
  cin >> nums[i];
  int a, b;
  memset(adj, 0, sizeof(adj));
  REP(i, K) {
    cin >> a >> b;
    cin >> adj[a][b];
  }
  Solution test;
  cout << test.solve() << endl;
}