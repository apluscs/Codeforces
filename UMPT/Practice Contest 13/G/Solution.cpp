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

int n, m, r, c, ml, mr, dist[2001][2001];  // max left, max right
string grid[2001];
struct Solution {
  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int solve() {
    deque<pair<int, int>> deq;
    REP(i, n)
    fill_n(dist[i], m, INT_MAX);
    dist[r][c] = 0, deq.push_back({r, c});
    while (!deq.empty()) {
      auto curr = deq.front();
      deq.pop_front();
      int i = curr.first, j = curr.second;
      // printf("i=%d, j=%d/, dist=%d\n", i, j, dist[i][j]);
      for (auto d : dir) {
        int ni = i + d[0], nj = j + d[1], nd = dist[i][j] + (d[1] == -1);  // did we go left
        if (out(ni, nj) || dist[ni][nj] <= nd) continue;
        dist[ni][nj] = nd;
        if (d[1] == -1)
          deq.push_back({ni, nj});
        else
          deq.push_front({ni, nj});
      }
    }
    int res = 0;
    REP(i, n) {
      REP(j, m) {
        if (dist[i][j] == INT_MAX) continue;
        int l = dist[i][j], r = j - c + l;
        if (l <= ml && r <= mr) res++;
      }
    }
    // REP(i, n) {
    //   REP(j, m)
    //   cout << dist[i][j] << " ";
    //   cout << endl;
    // }
    return res;
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m || grid[i][j] == '*'; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  cin >> n >> m >> r >> c >> ml >> mr;
  r--, c--;
  REP(i, n) {
    cin >> grid[i];
  }
  cout << test.solve() << endl;
}