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

int n, m;
vector<int> nums;

struct Solution {
  void solve() {
    int low = 0, high = m;
    while (low <= high) {
      int mid = (low + high) / 2;
      bool b = able(mid);
      // printf("%d, %d\n", mid, b);
      if (b)
        high = mid - 1;
      else
        low = mid + 1;
    }
    cout << low << endl;
  }
  bool able(int x) {
    int prev = 0;
    for (int i = 0; i != n; ++i) {
      int low = nums[i], high = (low + x) % m;
      if (high >= low && prev > high) return false;
      if (high < low && prev <= high) continue;
      prev = max(low, prev);
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  nums.resize(n);
  for (int i = 0; i != n; ++i) {
    cin >> nums[i];
  }
  Solution test;
  test.solve();
}
