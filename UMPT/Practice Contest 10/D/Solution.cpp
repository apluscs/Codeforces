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

using namespace std;
const int mod = 1e9 + 7;

int n, m;
vector<string> ss;
struct Solution {
  int solve() {
    vector<unordered_map<string, int>> min_rots(n);
    REP(i, n) {
      REP(j, m) {
        string s = ss[i].substr(j) + ss[i].substr(0, j);
        if (!min_rots[i].count(s)) min_rots[i][s] = j;
      }
    }
    int res = INT_MAX;
    REP(j, m) {
      string t = ss[0].substr(j) + ss[0].substr(0, j);
      int curr = j;
      FOR(i, 1, n) {
        if (!min_rots[i].count(t)) return -1;  // all should be able to
        curr += min_rots[i][t];
      }
      res = min(res, curr);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  cin >> n;
  ss.resize(n);
  REP(i, n) {
    cin >> ss[i];
  }
  m = ss[0].length();
  cout << test.solve() << endl;
}