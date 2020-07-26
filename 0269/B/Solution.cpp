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

int n, m;
vector<int> nums;
struct Solution {
  void solve() {
    vector<int> res;
    res.reserve(n);
    res.push_back(nums[0]);
    for (int i = 1; i != n; ++i) {
      if (nums[i] >= res.back())
        res.push_back(nums[i]);
      else {
        int j = upper_bound(res.begin(), res.end(), nums[i]) -
                res.begin(); // leave the ones == nums[i] be
        res[j] = nums[i];
      }
    }
    cout << n - res.size() << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i != n; ++i) {
      double x;
      cin >> nums[i] >> x;
    }
    Solution test;
    test.solve();
  }
}
