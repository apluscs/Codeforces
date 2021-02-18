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
const int mod = 1e9 + 7, MAXN = 200001;

int n, nums[MAXN];
pair<int, int> dp[MAXN];  // dp[i] = length, last index
struct Solution {
  vector<int> solve() {
    vector<int> res;
    pair<int, int> last;
    dp[0] = {0, -1};     // empty
    map<int, int> prev;  // prev[i] = which index you took to form longest subseq ending with i
    FORN(i, 1, n) {
      int x = nums[i], p = prev[x - 1];  // p = index preceding it
      dp[i] = {dp[p].first + 1, p};
      prev[x] = i;
      last = max(last, {dp[i].first, i});
    }
    int i = last.second;
    while (i) {
      res.push_back(i);
      i = dp[i].second;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  FORN(i, 1, n)
  cin >> nums[i];
  Solution test;
  auto res = test.solve();
  cout << res.size() << endl;
  for (int r : res) cout << r << " ";
  cout << endl;
}