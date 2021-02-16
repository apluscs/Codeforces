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
int n, m, lift[20][N];  // lift[i][j] = if at the end of interval j, which interval would we be at if we advanced 2^j intervals ahead?
vector<pair<int, int>> ivs, ques;
int nxt[N];  // next[i] = interval which latest end that starts <= i
struct Solution {
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }

  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
  vector<int> dp;
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
    lift[0][i] = nxt[ivs[i].second];  // end of this interval, move to the next interval (1 step)

    FOR(i, 1, 20) {  // advancing 2^i
      REP(j, n) {
        int h = lift[i - 1][j];
        if (h == -1)
          lift[i][j] = -1;
        else
          lift[i][j] = lift[i - 1][h];
        // cout << lift[i][j] << " ";
      }
      // cout << endl;
    }
    REP(q, m) {
      int x = ques[q].first, y = ques[q].second, j = nxt[x], sum = 1;  // v = first interval we need
      if (j == -1) {                                                   // even the start can't be covered
        res[q] = -1;
        continue;
      }
      // printf("x=%d, y=%d\n", x, y);
      FORD(i, 19, 0) {
        int h = lift[i][j];  // from j, what is the 2^i'th next iv?
        if (h == -1) continue;
        if (ivs[h].second < y) {   // don't count last interval yet
          sum += (1 << i), j = h;  // j+=(1<<i) should work? TODO
          // printf("jumps=%d, j=%d\n", (1 << i), j);
        }
      }                             // now j = last interval ending < y
      if(ivs[j].second >= y) res[q] = sum;  // already there
      else if (lift[0][j] == -1) {  // can't advance anymore
        res[q] = -1;
      } else
        res[q] = sum + 1;  // do we need the last interval?
    }
    return res;
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