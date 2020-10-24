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
vector<vector<int>> groups;
struct Solution {
  vector<int> reps, sizes;
  vector<int> solve() {
    vector<int> res(n);
    reps.resize(n,-1);
    sizes.resize(n);
    for (auto g : groups) {
      for (int i = 1; i < g.size(); ++i) {
        set_union(g[i], g[i - 1]);
      }
    }
    for (int i = 0; i != n; ++i) {
      int p = find(i);
      sizes[p]++;
    }
    for (int i = 0; i != n; ++i) {
      int p = find(i);
      res[i] = sizes[p];
    }
    return res;
  }
  void set_union(int a, int b) {
    // printf("a=%d, b=%d\n", a, b);
    int pa = find(a), prb = find(b);
    if (pa != prb) reps[pa] = prb;
  }

  int find(int a) {
    if (reps[a] != -1) {
      reps[a] = find(reps[a]);  // with path compression
      return reps[a];
    }
    return a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  groups.clear();
  groups.resize(m);
  Solution test;
  int k, i;
  while (m) {
    m--;
    cin >> k;
    while (k--) {
      cin >> i;
      groups[m].pb(--i);
    }
  }
  auto res = test.solve();
  for (auto r : res) cout << r << " ";
  cout << endl;
}