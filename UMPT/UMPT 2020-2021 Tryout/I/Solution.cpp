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
const int mod = 1e9 + 7, MAXN = 1e4 + 1;

int n, m, E, climb[MAXN];
vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];
struct Solution {
  ll res = LLONG_MAX;
  ll solve() {
    dijkstra();
    // REPN(i, n)
    //     cout << dist[i] << " ";
    // cout << endl;
    bellman_ford();
    return res;
  }
  void bellman_ford() {
    vector<ll> energy(n + 1, LLONG_MAX);  // energy[i] = min energy needed to reach node i
    energy[1] = 0;                        // don't need any energy to reach 1
    for (int lev = 1; lev < n; ++lev) {   // node-wise dist from 1
      auto prev = energy;                 // use this to reference one layer ago
      for (int x = 1; x <= n; ++x) {
        if (prev[x] == LLONG_MAX) continue;  // x is unreachable
        for (auto& p : adj[x]) {
          int y = p.first;
          ll w = p.second;
          ll ne = prev[x] + w + climb[x];  // need to climb at x and then walk
          if (ne > E) {                    // don't have enough energy
            // printf("ne=%lld, x=%d, y=%d\n", ne, x, y);
            res = min(res, lev * 2 + (ne - E) + dist[y]);  // *2 for every climb + walk, ne-E for time you need to rest, dist[y] for getting from y with 0 energy to N
          } else if (ne < energy[y]) {
            energy[y] = ne;
            // printf("**ne=%lld, x=%d, y=%d\n", ne, x, y);
            res = min(res, lev * 2 + dist[y]);
          }
        }
      }
    }
  }
  void dijkstra() {
    fill_n(dist + 1, n, LLONG_MAX);
    dist[n] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, n});
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int x = p.second;
      ll d = -p.first;
      if (d > dist[x]) continue;  //outdated
      for (auto& q : adj[x]) {
        int y = q.first, w = q.second;  // neighbor and weight
        ll nd = d + climb[y] + w + 2;
        if (nd >= dist[y]) continue;
        dist[y] = nd;
        pq.push({-nd, y});
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> E;
  FOR(i, 1, n)
  cin >> climb[i];
  int a, b, w;
  REP(i, m) {
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  Solution test;
  cout << test.solve() << endl;
}