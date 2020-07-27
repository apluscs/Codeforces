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

using namespace std;
const int mod = 1e9 + 7;

string s, t;
struct Solution {
  int n;
  void solve() {
    n = s.length();
    if (check(0, n - 1, 0, n - 1))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  bool check(int ss, int se, int ts, int te) {
    int len = se - ss + 1;
    bool b = same(ss, ts, len), res;
    if (len % 2)
      res = b;
    else if (b)
      res = true;
    else {
      int sm = (ss + se) / 2, tm = (ts + te) / 2;
      res = check(ss, sm, tm + 1, te) && check(sm + 1, se, ts, tm) ||
            check(ss, sm, ts, tm) && check(sm + 1, se, tm + 1, te);
    }
    // printf("ss=%d, se=%d, ts=%d, te=%d, res=%d\n", ss, se, ts, te, res);
    return res;
  }
  bool same(int ss, int ts, int len) {
    return equal(s.begin() + ss, s.begin() + ss + len, t.begin() + ts);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> s >> t;
    Solution test;
    test.solve();
  }
}
