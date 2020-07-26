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

string s;
struct Solution {
  void solve() { auto f = get_failure(s); }

  vector<int> get_failure(string str) {
    vector<int> res(str.length());
    for (int i = 0, j = 0; i != n; ++i) {
      while (j != 0 && s[j] != s[i]) j = res[j]
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> s;
    Solution test;
    test.solve();
  }
}
