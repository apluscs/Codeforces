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
vector<vector<int>> adj;
vector<vector<ll>> edges;
struct Solution {
  struct compar {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b) const {
      return a.first > b.first;
    }
  };
  vector<ll> solve() {
    vector<ll> res(n + 1, LLONG_MAX);  // distances,
    vector<bool> vis(n + 1);           // if processed or not
    res[n] = 0;                        // the source
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, compar> pq;
    pq.push(mp(0, n));
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int curr = p.second;  // the index
      if (vis[curr]) continue;
      vis[curr] = true;
      for (auto e : adj[curr]) {
        int j = edges[e][0] + edges[e][1] - curr;  // the other index
        ll new_dist = res[curr] + edges[e][2];
        if (vis[j] || new_dist >= res[j]) continue;
        pq.push(mp(new_dist, j));
        res[j] = new_dist;
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.clear();
  adj.resize(n + 1);  // n = "concert land"
  edges.resize(m + n);
  int a, b;
  ll w;
  REP(i, m) {
    cin >> a >> b >> w;
    a--, b--;
    adj[a].pb(i);
    adj[b].pb(i);
    edges[i] = {a, b, w * 2};
  }
  REP(i, n) {
    adj[i].pb(m + i);  // new edge = m + i
    adj[n].pb(m + i);  // goes from n to node i
    cin >> w;
    edges[i + m] = {i, n, w};
  }
  Solution test;
  auto res = test.solve();
  REP(i, n) {
    cout << res[i] << " ";
  }
  cout << endl;
}