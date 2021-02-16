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

const int N = 500005;
int n, m;
vector<pair<int, int>> ivs;
vector<vector<int>> ques;
int nxt[N];            // next[i] = interval which latest end that starts <= i
pair<int, int> dp[N];  // dp[i] = {last interval taken to cover r, #intervals taken to cover r (not counting the last one)} - from interval i
struct Solution {
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }

  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
  struct compar {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
      return a[1] < b[1];
    }
  };
  vector<int> solve() {
    vector<int> res(m);
    sort(ivs.begin(), ivs.end());
    pair<int, int> mx(0, -1);  // best interval so far that starts <= i
    for (int i = 0, j = 0; i != N; ++i) {
      while (j != n && ivs[j].first <= i) mx = max(mx, {ivs[j].second, j++});
      nxt[i] = mx.first <= i ? -1 : mx.second;  // no interval covers [i, i+1)
    }
    // REP(i, 100)
    // cout << nxt[i] << " ";
    // cout << endl;
    REP(i, n)
    dp[i] = {nxt[ivs[i].second], 1};  // next interval after this one that overlaps
    REP(i,m) ques[i].push_back(i);
    sort(ques.begin(), ques.end(),compar() ); // by right interval
    REP(q, m) {
      int x = ques[q][0], y = ques[q][1], j = nxt[x];  // j = first interval we need
      int s = find(j, y).second;
      res[ques[q][2]] = s == -1 ? -1 : s + 1;
    }
    return res;
  }
  pair<int, int> find(int j, int r) {                       // r = right bound of interval we're trying to cover, j = curr iv
    if (j == -1) return {-1, -1};                           // cannot reach
    if (ivs[j].second >= r) return {j, 0};                  // don't count last interval
    auto res = find(dp[j].first, r);                        // what was the latest interval j reached?
    if (res.first == -1) return dp[j] = {-1, -1};           // cannot reach
    return dp[j] = {res.first, res.second + dp[j].second};  // #steps to get to dp[j] + #steps from dp[j] to get to r
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int l, r;
  REP(i, n) {
    cin >> l >> r;
    ivs.pb({l, r});
  }
  Solution test;
  ques.clear();
  REP(i, m) {
    cin >> l >> r;
    ques.pb({l, r});
  }
  auto res = test.solve();
  REP(i, m) {
    cout << res[i] << endl;
  }
}