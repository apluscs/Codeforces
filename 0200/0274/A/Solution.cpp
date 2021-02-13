#include <assert.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
using namespace std;

int n, k;
vector<int> nums;

struct Solution {
  int solve() {
    if (k == 1) return n;
    unordered_map<int, int> dp;
    sort(nums.begin(), nums.end());
    for (int i = 0; i != n; ++i) {
      int v = nums[i], pre = v / k;
      dp[v] = 1;  // start of own chain
      if (v % k != 0) continue;
      dp[v] = dp[pre] + 1;
      dp[pre] = 0;
    }
    int res = 0;
    for (auto p : dp) {
      // cout << p.first << "," << p.second << endl;
      res += (p.second + 1) / 2;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  nums.resize(n);
  for (int i = 0; i != n; ++i) cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
}