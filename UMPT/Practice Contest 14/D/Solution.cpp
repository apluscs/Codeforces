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
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n, m, adj[101][101];
unordered_map<string, int> inds;
struct Solution {
  struct compar {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b) const {
      return a.first > b.first;
    }
  };
  string solve() {
    unordered_set<int> reachable;
    reachable.insert(n);
    int count = 0, res = 0;
    while (true) {
      unordered_map<int, int> next_layer;
      for (int i : reachable) {
        REP(j, n + 1) {
          int x = adj[i][j];
          if (!reachable.count(j) && x != -1) {
            if (!next_layer.count(j)) next_layer[j] = x;  // edge from i to j
            next_layer[j] = min(next_layer[j], x);
          }
        }
      }
      if(next_layer.empty()) break;
      for (auto p : next_layer) {
        reachable.insert(p.first);
        res += p.second;
      }
    }
    if (reachable.size() < n + 1) return "Impossible";
    return to_string(res);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  cin >> n >> m;
  string s, t;
  int x;
  inds.clear();
  REP(i, n) {
    cin >> s;
    inds[s] = i;  // 0 ... n-1
  }
  inds["English"] = n;
  memset(adj, -1, sizeof(adj));
  REP(i, m) {
    cin >> s >> t;
    cin >> x;
    int a = inds[s], b = inds[t];
    adj[a][b] = adj[b][a] = x;
  }
  cout << test.solve() << endl;
}