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

int n, m;
struct Offer {
  int x, y;
  ll val;
  Offer() {}
  Offer(int x, int y, ll val) : x(x), y(y), val(val) {}
  bool operator<(const Offer& b) const {
    return val < b.val;
  }
  bool operator==(const Offer& b) const {
    return val == b.val && x == b.x && y == b.y;
  }
  void print() {
    printf("x=%d, y=%d, val=%lld\n", x, y, val);
  }
};
vector<Offer> offers;
vector<ll> nums;
struct Solution {
  vector<int> reps;
  ll solve() {
    auto it = min_element(nums.begin(), nums.end());
    int low = it - nums.begin();
    reps.resize(n, -1);
    for (int i = 0; i != n; ++i) {
      if (i == low) continue;
      offers.push_back(Offer(low, i, nums[low] + nums[i]));
    }
    sort(offers.begin(), offers.end());
    ll res = 0;
    for (auto& e : offers) {
      if (set_union(e.x, e.y)) res += e.val;
    }
    return res;
  }
  int find(int a) {
    if (reps[a] != -1) {
      return reps[a] = find(reps[a]);  // with path compression;
    }
    return a;
  }

  // normal union find
  bool set_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      reps[pa] = pb;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  offers.resize(m);
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
  }
  int x, y;
  ll w;
  REP(i, m) {
    cin >> x >> y >> w;
    x--, y--;
    offers[i] = Offer(x, y, w);
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}
