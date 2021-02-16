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
vector<vector<int>> grid;
struct Solution {
  int solve() {
    vector<vector<int>> ds(n + m, vector<int>(2));
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) {
        ds[i + j][grid[i][j]]++;
      }
    }
    int res = 0;
    for (int i = 0, j = n + m - 2; i < j; ++i, --j) {
      res += min(ds[i][0] + ds[j][0], ds[i][1] + ds[j][1]);
      // cout << res << endl;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    grid.clear();
    grid.resize(n, vector<int>(m));
    REP(i, n) {
      REP(j, m) {
        cin >> grid[i][j];
      }
    }
    Solution test;
    auto res = test.solve();
    cout << res << endl;
    // cout << endl;
  }
}