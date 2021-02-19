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

int n;
ll hx, hy, ux, uy, lines[301][3];
struct Solution {
  int solve() {
    int res=0;
    REP(i, n) {
      ll h = lines[i][0] * hx + lines[i][1] * hy + lines[i][2], u = lines[i][0] * ux + lines[i][1] * uy + lines[i][2];
      res += h > 0 && u < 0 || h < 0 && u > 0;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> hx >> hy >> ux >> uy >> n;
  REP(i, n)
  cin >> lines[i][0] >> lines[i][1] >> lines[i][2];
  Solution test;
  cout << test.solve() << endl;
}