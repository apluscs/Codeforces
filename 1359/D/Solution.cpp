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
  int solve() {
    int res =
        0;  // don't bother in negative max, we can always do better with 0
    for (int k = 1; k != 31; ++k) {
      res = max(res, kadane(k) - k);
    }
    return res;
  }

  int kadane(int k) {
    int res = 0, curr = 0;
    for (int num : nums) {
      if (num > k) {
        curr = 0;
        continue;  // cannot include this num
      }
      curr += num;
      res = max(res, curr);
      if (curr < 0) curr = 0;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  for (int i = 0; i != n; ++i) cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
}