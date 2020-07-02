#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string s;
int q;

struct Solution {
  vector<vector<int>> dp;
  vector<vector<bool>> ispal;
  int n;
  void solve() {
    n = s.length();
    precompute_dp();
    int l, r;
    while (q--) {
      cin >> l >> r;
      l--, r--;
      cout << dp[l][r] << " ";
    }
    cout << endl;
  }

  void precompute_dp() {
    dp.resize(n, vector<int>(n, 0));
    ispal.resize(n, vector<bool>(n, true));
    for (int i = 0; i != n; ++i) {
      dp[i][i] = 1;
    }
    for (int len = 2; len != n + 1; ++len) {  // diags northeast of main one
      for (int i = 0, j = i + len - 1; j < n; i++, j++) {
        ispal[i][j] = ispal[i + 1][j - 1] && s[j] == s[i];
        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + ispal[i][j];
      }
    }
    // for (int i = 0; i != n; ++i) {
    //   for (int j = i; j != n; ++j) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> q;
  Solution test;
  test.solve();
}
