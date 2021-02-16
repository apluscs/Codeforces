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
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n;
string s;
struct Solution {
  vector<int> vis;
  vector<vector<char>> adj;
  string solve() {
    n = s.length();
    string res = string(1, s[0]);
    int j = 0;  // track position of last placed char
    for (int i = 1; i != n; ++i) {
      auto c = s[i];
      int m = res.length(), k = res.find(c);
      if (k != -1) {  // already in there, must ensure it's next to j
        if (k != j - 1 && k != j + 1) return "NO";
      } else if (j == 0) {
        if (m == 1 || res[j + 1] != c) res = string(1, c) + res;  // prepend c to front
      } else if (j == m - 1) {
        if (res[j - 1] != c) res += string(1, c);  // already taken care of
      } else {                                     // j is in the middle
        if (res[j - 1] != c && res[j + 1] != c) return "NO";
      }
      j = res.find(c);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (res.find(c) == -1) res += c;
    }
    return "YES\n" + res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    Solution test;
    auto res = test.solve();
    cout << res << endl;
  }
}