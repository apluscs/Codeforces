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

int n, tree[1000005], nums[1000001];
struct Solution {
  int solve() {
    REPN(i, n)
    if (count(i)) return i;
    return 0;
  }
  void remove(int i) {  // remove i'th value
    int v = get_ith(i);
    // printf("i=%d, v=%d\n", i, v);
    update(v, -1);
  }
  int get_ith(int i) {
    int low = 1, high = n;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (count(mid) < i)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }
  void update(int v, int d) {  // d is the incoming change
    for (int i = v; i <= n; i += (i & -i)) tree[i] += d;
  }
  int count(int v) {
    int res = 0;
    for (int i = v; i; i -= (i & -i)) res += tree[i];
    // printf("v=%d, count=%d\n", v, res);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(tree, 0, sizeof(tree));
  Solution test;
  int x, T;
  cin >> n >> T;
  REP(i, n) {
    cin >> x, test.update(x, 1);
  }
  REP(i, T) {
    cin >> x;
    if (x > 0)
      test.update(x, 1);
    else
      test.remove(-x);
  }
  cout << test.solve() << endl;
}