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
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n, pts[100001][2];
struct Solution {
  vector<int> res = {0, 1, -1};
  vector<int> solve() {
    FOR(i, 2, n) {
      if (area(pts[0][0], pts[0][1], pts[1][0], pts[1][1], pts[i][0], pts[i][1])) {
        res[2] = i;
        break;
      }
    }
    FOR(i, 2, n) {
      if (i == res[2]) continue;
      ll a = area(pts[res[0]][0], pts[res[0]][1], pts[res[1]][0], pts[res[1]][1], pts[i][0], pts[i][1]),
         b = area(pts[res[0]][0], pts[res[0]][1], pts[res[2]][0], pts[res[2]][1], pts[i][0], pts[i][1]),
         c = area(pts[res[1]][0], pts[res[1]][1], pts[res[2]][0], pts[res[2]][1], pts[i][0], pts[i][1]);
      // printf("a=%lld, b=%lld,c=%d\n", a, b, c);
      if (a + b + c == area(pts[res[0]][0], pts[res[0]][1], pts[res[1]][0], pts[res[1]][1], pts[res[2]][0], pts[res[2]][1])) {  // point is in triangle
        // printf("i=%d, a=%lld, b=%lld, res=%d, %d, %d\n", i, a, b, res[0], res[1], res[2]);
        if (!a || !b) {
          res[0] = i;
        } else
          res[2] = i;
      }
    }
    return res;
  }
  ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    // printf("x1=%lld, y1=%lld, x2=%lld, y2=%lld, x3=%lld, y3=%lld\n", x1, y1, x2, y2, x3, y3);
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  }
};
void print(vector<int> nums) {
  for (auto num : nums) cout << num + 1 << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  REP(i, n) {
    cin >> pts[i][0] >> pts[i][1];
  }
  print(test.solve());
}