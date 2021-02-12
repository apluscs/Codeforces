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
const int mod = 1e9 + 7;

int n, D, L, R, K;
vector<int> nums;
struct Solution {
  vector<ll> pre;
  Solution() {
    pre.resize(n);
    pre[0] = nums[0];
    for (int i = 1; i != n; ++i) {
      pre[i] = nums[i] + pre[i - 1];
    }
  }
  ll solve() {
    ll low = 1, high = 1e14;
    while (low <= high) {
      ll mid = (low + high) / 2;  // max load per truck
      if (able(mid))                // can handle it
        high = mid - 1;
      else  // must increase limit
        low = mid + 1;
      // cout << endl;
    }
    return low;
  }
  bool able(ll cap) {
    int used = 0;
    // printf("cap=%lld, ", cap);
    for (int i = L; i <= R;) {
      ll x = i ? pre[i - 1] : 0;  // pref sum before i
      // printf("x=%lld, ", x);
      auto it = upper_bound(pre.begin(), pre.end(), x + cap);  // first one to break the truck
      int j = it - pre.begin();
      used++;
      if (used > K) return false;  // too many trucks
      i = j;                       // move on to the next segment
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> D;
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  Solution test;
  REP(i, D) {
    cin >> L >> R >> K;
    L--, R--;
    auto res = test.solve();
    cout << res << endl;
  }
}