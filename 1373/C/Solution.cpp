#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

string s;

struct Solution {
  int n;
  ll solve() {
    n = s.length();
    vector<int> dp(n);
    int curr = 0, low = 0;
    for (int i = 0; i != n; ++i) {
      curr += s[i] == '+' ? 1 : -1;
      low = min(low, curr);
      dp[i] = max(-low, 0);  // lowest balance encountered before i
    }
    ll res = 0;
    for (int i = 0; i != n; ++i) {
      res += -low - dp[i] + 1;  // #cycles in which we encounter i
    }
    return res - low;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t != T + 1; ++t) {
    cin >> s;
    Solution test;
    cout << test.solve() << endl;
  }
}