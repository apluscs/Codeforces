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
vector<vector<int>> adj;
vector<int> possible, relorder;
struct Solution {
  struct compar {
    bool operator()(const int a, const int b) const {
      return relorder[a] < relorder[b];
    }
  };
  string solve() {
    queue<int> que;
    vector<bool> vis(n);
    vector<int> obs;
    que.push(0);
    vis[0] = true;
    relorder.resize(n);
    REP(i, n) {
      relorder[possible[i]] = i;
    }
    REP(i, n) {
      sort(adj[i].begin(), adj[i].end(), compar());
    }
    while (!que.empty()) {
      int s = que.size();
      for (; s; --s) {
        int curr = que.front();
        que.pop();
        obs.pb(curr);
        for (auto nei : adj[curr]) {
          if (vis[nei]) continue;
          vis[nei] = true;
          que.push(nei);
        }
      }
    }
    return obs == possible ? "Yes" : "No";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  adj.clear();
  adj.resize(n);
  possible.resize(n);
  Solution test;
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  REP(i, n) {
    cin >> possible[i];
    possible[i]--;
  }
  auto res = test.solve();
  cout << res << endl;
}