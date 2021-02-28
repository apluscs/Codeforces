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
#include <set>
#include <stack>
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
  cout << arr[i] << endl; \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n, m, A[2], B[2];
string grid[100];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[101][101];
struct Solution {
  vector<int> solve() {
    preprocess();
    REP(i, n)
    flood_outside(i, 0), flood_outside(i, m - 1);
    REP(j, m)
    flood_outside(0, j), flood_outside(n - 1, j);
    vector<int> res(3);
    int a, b, both = 0;
    REP(i, n)
    REP(j, m)
    both += grid[i][j] == '.';
    memset(vis, 0, sizeof(vis));
    bool found = false;
    REP(i, n) {
      REP(j, m) {
        if (grid[i][j] != 'A') continue;
        for (auto d : dir) {
          int ni = i + d[0], nj = j + d[1], pi = i - d[0], pj = j - d[1];
          if ((out(pi, pj) || grid[pi][pj] == 'O') && (!out(ni, nj) && grid[ni][nj] == '.')) {
            a = flood_inside(ni, nj, 'A'), found = true;
            break;
          }
        }
        if (found) break;
      }
      if (found) break;
    }
    // printf("both=%d, a=%d, b=%d\n", both, a, b);

    // print_arr(grid, n);
    memset(vis, 0, sizeof(vis)), found = false;
    REP(i, n) {
      REP(j, m) {
        if (grid[i][j] != 'B') continue;
        for (auto d : dir) {
          int ni = i + d[0], nj = j + d[1], pi = i - d[0], pj = j - d[1];
          if ((out(pi, pj) || grid[pi][pj] == 'O') && (!out(ni, nj) && grid[ni][nj] == '.')) {
            b = flood_inside(ni, nj, 'B'), found = true;
            break;
          }
        }
        if (found) break;
      }
      if (found) break;
    }

    int intersect = a + b - both;
    return {a - intersect, b - intersect, intersect};
  }
  int flood_inside(int i, int j, char bad) {
    if (out(i, j) || grid[i][j] == bad || grid[i][j] == 'I' || vis[i][j]) return 0;
    int res = 0;
    vis[i][j] = true;
    if (grid[i][j] == '.') res++;
    for (auto d : dir) res += flood_inside(i + d[0], j + d[1], bad);
    // printf("i=%d, j=%d,res=%d, c=%c\n", i, j, res, grid[i][j]);
    return res;
  }
  void flood_outside(int i, int j) {
    if (out(i, j) || grid[i][j] != '.') return;
    grid[i][j] = 'O';
    for (auto d : dir) flood_outside(i + d[0], j + d[1]);
  }
  void preprocess() {
    FOR(i, 1, n - 1) {
      FOR(j, 1, m - 1) {
        if (grid[i][j] != '.' && grid[i - 1][j] != '.' && grid[i + 1][j] != '.' && grid[i][j - 1] != '.' && grid[i][j + 1] != '.') grid[i][j] = 'I';
      }
    }
    REP(i, n)
    REP(j, m) {
      if (grid[i][j] == 'A') grid[i][j] = 'X', flood_boundary(i, j, 'A');
      if (grid[i][j] == 'B') grid[i][j] = 'X', flood_boundary(i, j, 'B');
    }
  }
  // void flood_boundary(int i, int j, char c) {
  //   if (out(i, j) || grid[i][j] != 'X') return;
  //   grid[i][j] = c;
  //   for (auto d : dir) {
  //     flood_boundary(i + d[0], j + d[1], c);
  //   }
  // }
  void flood_boundary(int i, int j, char c) {
    if (grid[i][j] == c) return;
    grid[i][j] = c;
    // print_arr(grid, n);
    for (auto d : dir) {
      int ni = i + d[0], nj = j + d[1];
      if (out(ni, nj)) continue;
      if (grid[ni][nj] == 'X')
        flood_boundary(ni, nj, c);
      else if (grid[ni][nj] == 'I')
        flood_boundary(i + 2 * d[0], j + 2 * d[1], c);
    }
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};
void print(vector<int> nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  Solution test;
  REP(i, n) {
    cin >> grid[i];
  }
  print(test.solve());
}