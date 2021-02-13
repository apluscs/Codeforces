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

int x;
string s;
struct Solution {
  void solve() {
    ll len = s.length();
    for (int i = 0; i != x; ++i) {
      ll r = (len - i - 1 + mod) % mod, k = s[i] - '1';
      len = (len + r * k) % mod;
      string sr;
      if (s.length() < x) sr = s.substr(i + 1);  // need this optimization
      while (k--) {
        s += s.length() < x ? sr : "";
      }
    }
    cout << len << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> x >> s;
    Solution test;
    test.solve();
  }
}
