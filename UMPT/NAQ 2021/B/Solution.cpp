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
double pi = 3.14159265358979323846;
struct Light {
  int x, y;
  double a, d, s, e;
  Light(int x, int y, double a, double d) : x(x), y(y), a(a), d(d) {
    d *= sqrt(x * x + y * y);
    s = a - d, e = a + d;
    if (s < 0) s += pi, e += pi;
  }
};
struct compar {
  bool operator()(const Light& a, const Light& b) const {
    return a.s < b.s;
  }
};
int n;
vector<Light> lts;
struct Solution {
  string solve() {
    double start = lts[0].s, end = lts[0].e;
    for (auto lt : lts) {
      if (lt.s <= end)
        end = max(end, lt.e);  // extend this chain
      else {                   // should just be one big chain
        return "NO";
      }
    }
    return end - start >= 2 * pi ? "YES" : "NO";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int x, y;
  double a, d;
  REP(i, n) {
    cin >> x >> y >> a >> d;
    lts.push_back(Light(x, y, a, d));
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}