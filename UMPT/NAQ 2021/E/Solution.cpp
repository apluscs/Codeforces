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
vector<vector<pair<int, int>>> adj;
struct Solution {
  ll solve() {
    return dfs(0, 0, -1);
  }
  ll dfs(int i, int k, int p) {
    ll s = 0, m = 0, res = 0;
    for (auto& pr : adj[i]) {
      if (pr.first == p) continue;
      s += pr.second;
      res += dfs(pr.first, pr.second, i);
      m = max(m, (ll)pr.second);
    }
    // printf("i=%d, res=%d\n", i, res);
    if (k > s)
      res += k - s;
    else
      res -= min((s - k) / 2, s - m);
    printf("i=%d, res=%d\n", i, res);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  adj.resize(n);
  int a, b, w;
  REP(i, n - 1) {
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  Solution test;
  cout << test.solve() << endl;
}