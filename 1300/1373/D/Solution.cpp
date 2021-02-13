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

int n;
vector<int> nums;

struct Solution {
  ll solve() {
    ll res = 0;
    for (int i = 0; i != n; ++i) {
      if (i % 2 == 0) res += nums[i];
      nums[i] = i % 2 ? nums[i] : -nums[i];
    }
    return res + max(kadane(0), kadane(1));
  }

  ll kadane(int k) {
    ll curr = 0, res = 0;
    for (int i = k; i < n; ++i) {  // %2 != k --> these are decision points
      curr += nums[i];
      if (i % 2 == k) continue;  // otherwise we have even number of nums
      res = max(res, curr);
      curr = max(curr, 0LL);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i != n; ++i) cin >> nums[i];
    Solution test;
    cout << test.solve() << endl;
  }
}