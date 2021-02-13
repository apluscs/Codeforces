#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

int n, x;
string s;
struct Solution {
  void solve() {
    ll bs = 0, curr = 0, res = 0;
    bool found = false;
    for (int i = 0; i != n; ++i) {
      bs += s[i] == '0' ? 1 : -1;
      if (bs == x)
        found = true;
    }
    if (bs == 0 && found) {
      cout << "-1" << endl;
      return;
    }
    if (x == 0)
      res++; // empty string
    for (int i = 0; i != n; ++i) {
      curr += s[i] == '0' ? 1 : -1;
      if (bs == 0) { // cycle contributes nothing
        res += curr == x;
        continue;
      }
      res += bs * (x - curr) >= 0 && (x - curr) % bs == 0;
    }
    cout << res << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> x >> s;
    Solution test;
    test.solve();
  }
}
