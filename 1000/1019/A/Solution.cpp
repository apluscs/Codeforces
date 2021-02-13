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
vector<vector<int>> nums;

struct Solution {
  void solve() {
    for (int i = 1; i <= m; ++i) {
      sort(nums[i].begin(), nums[i].end());
    }
    ll res = LLONG_MAX;
    for (int x = 1; x <= n; ++x) {
      res = min(res, votes(x));
    }
    cout << res << endl;
  }

  ll votes(int x) {  // Minimum #votes you need to secure
    ll res = 0, have = nums[1].size();
    // Eliminate threats.
    priority_queue<int, vector<int>, greater<int>> pq;  // need min at top
    for (int i = 2; i <= m; ++i) {
      int s = nums[i].size(), start = 0;
      if (s >= x) {
        for (int j = 0; j <= s - x; ++j) {
          have++;
          res += nums[i][j];
        }
        start = s - x + 1;
      }
      for (int j = start; j < s; ++j) {
        pq.push(nums[i][j]);
      }
    }
    while (have < x) {
      res += pq.top();
      pq.pop();
      have++;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  nums.resize(m + 1);
  for (int i = 0, p, c; i != n; ++i) {
    cin >> p >> c;
    nums[p].push_back(c);
  }
  Solution test;
  test.solve();
}
