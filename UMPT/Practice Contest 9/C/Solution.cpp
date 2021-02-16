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
string s;
struct Solution {
  int solve() {
    int frq[10] = {0}, m = s.length(), res = m;
    for (char c : s) frq[c - '0']++;
    for (int f : frq) res = min(res, m - f);  // how many to remove to get unanimous?
    REP(i, 10)
    REP(j, 10) {
      if (i == j) continue;
      res = min(res, m - evens(i + '0', j + '0'));
    }
    return res;
  }
  int evens(char a, char b) {  // max length subsequence where a = even index, b = odd index
    int res = 0;               // a is the next one
    for (char c : s) {
      if (c == a) res++, swap(a, b);  // now b is next one
    }
    res -= res % 2;
    // printf("a=%c, b=%c, res=%d\n", a, b, res);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  while (T--) {
    cin >> s;
    auto res = test.solve();
    cout << res << endl;
  }
}