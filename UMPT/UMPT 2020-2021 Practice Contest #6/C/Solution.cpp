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

int n;
vector<pair<string, string>> ss;
vector<int> order;
struct Solution {
  string solve() {
    string prev = ss[order[0]].first;
    // cout << prev << endl;
    REPN(j, n - 1) {
      int i = order[j];
      string a = ss[i].first, b = ss[i].second;
      if (b < prev) {
        // cout << b << "," << prev << endl;
        return "NO";  // a < b< prev, but either a or b needs to be > prev
      }
      if (a < prev) {
        prev = b;
        continue;
      }
      prev = a;
      // cout << j << " ";
      // cout << prev << endl;
    }
    return "YES";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ss.resize(n);
  string f, s;
  REP(i, n) {
    cin >> f >> s;
    string a = min(f, s), b = max(f, s);
    ss[i] = mp(a, b);  // smaller one first
  }
  order.resize(n);
  REP(i, n) {
    cin >> order[i];
    order[i]--;
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}