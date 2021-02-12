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

int n=8;
vector<string> grid;
struct Solution {
  string solve() {
    REP(i, n) {
      REP(j, m)
      dfs(i, j);
    }
    int res = 0;
    for (string& s : grid) {
      for (char c : s) res += c == 'B';
    }
    // print(grid);
    return res;
  }
  bool out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
  void print(vector<string>& nums) {
    for (auto num : nums) cout << num << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  REP(i, n) {
    cin >> grid[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}