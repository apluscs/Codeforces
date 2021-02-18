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

int n, k;
string s;
struct Solution {
  int solve() {
    int res = 0, G = n / k;
    for (int i = 0; i != (k + 1) / 2; ++i) {
      int frq[26] = {0}, total = (2 - (i == k / 2 && k % 2)) * G, best = 0;  // does each group contribute 1 or 2?
      for (int g = 0; g < n; g += k) {                                       // which group
        frq[s[g + i] - 'a']++;
        if (total == 2 * G) frq[s[g + k - i - 1] - 'a']++;
      }
      for (int f : frq) best = max(best, f);
      res += total - best;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k >> s;
    cout << test.solve() << endl;
  }
}