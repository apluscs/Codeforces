#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n;
vector<int> nums;

struct Solution {
  int solve() {
    if (n == 1 || n % 2 == 0) return -1;
    int res = 0;
    for (int i = n; i; --i) {
      res += nums[i];
      int p = i / 2;
      nums[p] = max(0, nums[p] - nums[i]);
      int s = i & 1 ? p * 2 : p * 2 + 1;
      nums[s] = max(0, nums[s] - nums[i]);
      nums[i] = 0;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  nums.resize(n + 1);
  for (int i = 1; i != 1 + n; ++i) {
    cin >> nums[i];
  }
  Solution test;
  cout << test.solve() << endl;
}