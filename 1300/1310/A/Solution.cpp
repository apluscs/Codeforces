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

int n;
vector<vector<int>> nums;
struct Solution {
  void solve() {
    sort(nums.begin(), nums.end());
    // for (int i = 0; i != n; ++i) cout << nums[i][0] << " ";
    // cout << endl;
    priority_queue<int> pq;
    int i = 0, curr = -1;
    ll sum = 0, res = 0;
    while (i < n || !pq.empty()) {
      if (pq.empty()) {
        curr = nums[i][0];
      }
      while (i < n && nums[i][0] == curr) {
        sum += nums[i][1];
        pq.push(nums[i++][1]);
      }
      sum -= pq.top();
      pq.pop();
      res += sum;
      curr++;
    }
    cout << res << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n;
    nums.resize(n, {0, 0});
    for (int i = 0, x; i != n; ++i) {
      cin >> x;
      nums[i][0] = x;
    }
    for (int i = 0, x; i != n; ++i) {
      cin >> x;
      nums[i][1] = x;
    }
    Solution test;
    test.solve();
  }
}
