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

int n, m;  // target, hole
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string> grid;
struct Solution {
  vector<vector<pair<int,int>>> parent;
  struct Clue {
    string id;
    int total_value, obs_value;
    Clue(string id, int total_value, int obs_value) : id(id), total_value(total_value), obs_value(obs_value) {}
    void print() {
      printf("id=%s, total=%d, obs=%d\n", id.c_str(), total_value, obs_value);
    }
  };

  struct compar {
    bool operator()(const Clue& a, const Clue& b) const {
      double ra = double(a.obs_value) / a.total_value, rb = double(b.obs_value) / b.total_value;
      if (ra != rb) return ra < rb;
      return a.id[1] != b.id[1] ? a.id[1] > b.id[1] : a.id[0] > b.id[0];  // across before down
    }
  };
  priority_queue<Clue, vector<Clue>, compar> pq;
  vector<string> solve() {
    precompute();
    unordered_set<string> full;
    vector<string>res;
    while (!pq.empty()) {
      auto s = pq.top();
      pq.pop();
      s.print();
      if(full.count(s))continue;
      res.pb(s.id);

    }
    return res;
  }
  void precompute() {
    int count = 1;
    REP(i, n) {
      REP(j, m) {
        if (grid[i][j] == '#') continue;
        bool one = false;
        if (out(i - 1, j) || grid[i - 1][j] == '#')
          pq.push(make_clue(count, i, j, 2)), one = true;
        if (out(i, j - 1) || grid[i][j - 1] == '#')
          pq.push(make_clue(count, i, j, 0)), one = true;
        if (one) count++;
      }
    }
  }
  Clue make_clue(int count, int si, int sj, int d) {
    int len = 0, total_value = 0, obs_value = 0, i = si, j = sj, curr;
    while (!out(i, j) && grid[i][j] != '#') {
      len++;
      total_value += len;
      i += dirs[d][0], j += dirs[d][1];
    }
    i = si, j = sj, curr = len;
    while (!out(i, j) && grid[i][j] != '#') {
      if (grid[i][j] != '.') obs_value += curr;
      curr--;
      i += dirs[d][0], j += dirs[d][1];
    }
    return Clue(to_string(count) + (d ? "D" : "A"), total_value, obs_value);
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  grid.resize(n);
  REP(i, n) {
    cin >> grid[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}