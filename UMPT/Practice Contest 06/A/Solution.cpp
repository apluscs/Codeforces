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

int n;
vector<int> nums;
struct Solution {
  vector<int> solve() {
    vector<int> factors, res;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        factors.pb(i);
        if (i * i != n) factors.pb(n / i);
      }
    }
    sort(factors.begin(), factors.end());
    for (int f : factors) {
      if (res.empty() || f % res.back() == 0) res.pb(f);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  auto res = test.solve();
  for (auto r : res) cout << r << " ";
  cout << endl;
}