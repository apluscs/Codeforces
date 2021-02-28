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
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n, m;
string ss[10];
struct Solution {
  string res, curr;
  vector<string> opts;
  bool bad[10];
  string solve() {
    res = "-1", curr = "", opts.clear(), opts.resize(m), memset(bad, 0, sizeof(bad));
    REP(i, m) {  // col
      REP(j, n) {
        if (opts[i].find(ss[j][i]) == -1) opts[i] += ss[j][i];
      }
    }
    dfs(0);
    return res;
  }
  void dfs(int i) {  // bad = which strings in ss have 1 flag alr
    if (i == m) {
      // cout << curr << endl;
      if (res == "-1") res = curr;
      return;
    }
    bool temp[10];
    copy(bad, bad + n, temp);
    for (char c : opts[i]) {
      bool flag = false;
      REP(j, n) {
        if (ss[j][i] != c) {
          if (bad[j]) {
            flag = true;
            break;
          }
          bad[j] = true;
        }
      }
      if (flag) {
        copy(temp, temp + n, bad);
        continue;
      }
      curr += c;
      dfs(i + 1);
      curr.pop_back();
      copy(temp, temp + n, bad);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    REP(i, n) {
      cin >> ss[i];
    }
    cout << test.solve() << endl;
  }
}