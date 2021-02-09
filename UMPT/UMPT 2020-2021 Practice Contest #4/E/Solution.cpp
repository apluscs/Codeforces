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
vector<vector<int>> adj;
vector<int> edges;
struct Solution {
  vector<int> vis, res;
  vector<int> solve() {
    vis.resize(n);
    res.resize(m, 1);
    for (int i = 0; i != n; i++)
      dfs(i);
    return res;
  }
  void dfs(int curr) {  //goal is to make the last edge in the cycle = 2
    if (vis[curr] == 2) return;
    vis[curr] = 1;
    for (auto e : adj[curr]) {
      int to = edges[e];
      if (vis[to] == 1) {
        res[e] = 2;
        continue;
      }
      dfs(to);
    }
    vis[curr] = 2;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.clear();
  adj.resize(n);
  edges.resize(m);
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    a--, b--;
    adj[a].pb(i);  // index of outgoing edge
    edges[i] = b;  // end point of that edge
  }
  Solution test;
  auto res = test.solve();
  cout << *max_element(res.begin(),res.end()) << endl;
  for (auto r : res) cout << r << " ";
  cout << endl;
}