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

int n, nums[5001];
pair<int, int> ST[5001][14];
struct Solution {
  ll solve() {
    build_ST();
    return paint(0, n - 1, 0);
  }
  ll paint(int s, int e, int b) {  // b=base, already painted
    if (s > e) return 0;
    int i = query(s, e), h = nums[i];
    // printf("s=%d, e=%d, i=%d, h=%d, b=%d\n", s, e, i, h, b);
    ll res = min(e - s + (ll)1, paint(s, i - 1, h) + paint(i + 1, e, h) + h - b);  // h-b = #horz strokes
    // printf("s=%d, e=%d, i=%d, h=%d, b=%d, res=%lld\n", s, e, i, h, b, res);
    return res;
  }

  void build_ST() {
    for (int i = 0; i < n; ++i) ST[i][0] = {nums[i], i};
    for (int j = 1; j != 18; ++j)
      for (int i = 0; i + (1 << j) <= n; ++i)
        ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
  }
  int query(int s, int e) {          // find argmax nums[i] for this range
    int x = floor(log2(e - s + 1));  // log2(range)
    return min(ST[s][x], ST[e - (1 << x) + 1][x]).second;
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