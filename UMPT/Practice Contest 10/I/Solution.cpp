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

int n, m, w, nums[100001], add[100001];
struct Solution {
  int solve() {
    int low = 1, high = 1e9 + 1e5 + 5;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (able(mid))
        low = mid + 1;
      else
        high = mid - 1;
    }
    return high;
  }
  bool able(int k) {  // add[i] = how much additional water you need to get plant i to height >= k
    ll curr = 0, res = 0;
    memset(add, 0, sizeof(add));
    REP(i, n) {
      curr -= i >= w ? add[i - w] : 0;  // not included in window anymore
      if (curr + nums[i] < k) {
        res += add[i] = k - (curr + nums[i]);  // curr + nums[i] = heights from prev waterings + curr height
        curr += add[i];
      }
      // printf("k=%d, res=%lld,curr=%d\n", k, res, curr);
    }
    return res <= m;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> w;
  REP(i, n)
  cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
}