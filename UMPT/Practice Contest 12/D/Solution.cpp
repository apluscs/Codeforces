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

int n, first_diff[200001];
char nums[200001];
struct Solution {
  int solve() {
    int diff = 0, res = 2 * n;
    memset(first_diff, -1, sizeof(first_diff));  // first_diff[i] = first index j where cumm diff [n, j] is i
    first_diff[100000] = 2 * n;                  // right end + 1 = 0 diff
    FORD(i, 2 * n - 1, n) {                      // going rightward from right end
      diff += nums[i] == '1' ? 1 : -1;
      first_diff[diff + 100000] = i;
      // printf("diff=%d, first_diff[diff]=%d\n", diff, first_diff[100000 + diff]);
    }
    diff = 0;
    // printf("first_diff[-1]=%d\n", first_diff[100000 - 1]);
    REP(i, n) {  // going leftwards from left end
      diff += nums[i] == '1' ? 1 : -1;
      int j = first_diff[100000 - diff];
      if (j == -1) continue;
      int x = 2 * n - (2 * n - j + i + 1);

      res = min(res, x);
      // printf("i=%d, j=%d, x=%d, diff=%d, first_diff[-diff]=%d \n", i, j, x, diff, first_diff[100000 - diff]);
    }
    return min(res, first_diff[100000]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    REP(i, 2 * n) {
      cin >> nums[i];
    }
    cout << test.solve() << endl;
  }
}