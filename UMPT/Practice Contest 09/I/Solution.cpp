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

int n, nums[500001];
ll lol[500001], lor[500001], hil[500001], hir[500001];
struct Solution {
  ll solve() {
    lol[0] = hil[0] = nums[0];
    FOR(i, 1, n) {
      lol[i] = min(nums[i] - hil[i - 1], min(lol[i - 1] - nums[i], lol[i - 1] + nums[i]));
      hil[i] = max(nums[i] - lol[i - 1], max(hil[i - 1] - nums[i], hil[i + 1] + nums[i]));
    }
    lor[n - 1] = hir[n - 1] = nums[n - 1];
    FORD(i, n - 2, 0) {
      lor[i] = min(nums[i] - hir[i + 1], min(lor[i + 1] - nums[i], lor[i + 1] + nums[i]));
      hir[i] = max(nums[i] - lor[i + 1], max(hir[i + 1] - nums[i], hir[i + 1] + nums[i]));
    }
    ll res = LLONG_MIN;
    REP(i, n) {
      ll a = i == 0 ? 0 : lol[i - 1], b = i == n - 1 ? 0 : lor[i + 1];
      res = max(res, nums[i] - a - b);
    }
    // print_arr(lol, n);
    // print_arr(hil, n);
    // print_arr(lor, n);
    // print_arr(hir, n);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, n)
  cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
}