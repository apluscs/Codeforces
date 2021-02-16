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

int n, m;
ll curr;
vector<int> nums;
struct Solution {
  int solve() {
    sort(nums.begin(), nums.end());
    int i;
    for (i = n - 1; curr > 0 && i != -1; --i) {
      curr -= nums[i];
      // cout << curr << endl;
    }
    if (curr > 0) return -1;
    return n - i - 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  curr = -m;
  nums.resize(n);
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    curr += a;        // curr = inital overflow
    nums[i] = a - b;  // how much storage will drop
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}