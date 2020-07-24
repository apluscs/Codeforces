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

int n, m, mod = 1e9 + 7;

// https://codeforces.com/blog/entry/70720?#comment-552214
struct Solution {
  void solve() {
    int h = max(n, m);
    vector<ll> dp(h + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; ++i) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << (dp[n] + dp[m] - 1 + mod) % mod * 2 % mod << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  Solution test;
  test.solve();
}
