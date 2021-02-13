#include <assert.h>
#include <math.h>

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

int n;
vector<int> nums;

struct Solution {
  void solve() {
    sort(nums.begin(), nums.end());
    int res = 0, prev = 0;  // cannot use 0
    for (int x : nums) {
      res++;
      if (x - 1 > prev) {
        prev = x - 1;
      } else if (x > prev) {
        prev = x;
      } else if (x + 1 > prev) {
        prev = x + 1;
      } else {
        res--;  // couldn't fit this one in
      }
    }
    printf("%d\n", res);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  for (int i = 0; i != n; ++i) cin >> nums[i];
  Solution test;
  test.solve();
}