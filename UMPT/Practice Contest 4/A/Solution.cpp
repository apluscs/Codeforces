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

int n, s;
vector<int> ta, tb;
struct Solution {
  vector<bool> vis;
  string solve() {
    vis.resize(n);
    dfs(0);
    if (vis[s]) return "YES";
    return "NO";
  }
  void dfs(int curr) {
    if (vis[curr]) return;
    vis[curr] = true;
    int i = curr;
    if (ta[curr]) {  // we can go right
      for (int i = curr; i != n; ++i)
        if (ta[i]) dfs(i);  // train a stops at i
    }
    if (tb[curr]) {  // we can go right
      for (int i = curr; i != -1; --i)
        if (tb[i]) dfs(i);  // train b stops at i
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  s--;
  ta.resize(n);
  tb.resize(n);
  REP(i, n) {
    cin >> ta[i];
  }
  REP(i, n) {
    cin >> tb[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}