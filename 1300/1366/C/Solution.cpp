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

int n, m;
vector<vector<int>> nums;

struct Solution {
  int solve() {
    vector<vector<int>> ds(n + m, vector<int>(2));
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) {
        cin >> nums[i][j];
        ds[i + j][nums[i][j]]++;
      }
    }
    int res = 0;
    for (int i = 0, j = n + m - 2; i < j; ++i, --j) {
      res += min(ds[i][0] + ds[j][0], ds[i][1] + ds[j][1]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t != T + 1; ++t) {
    cin >> n >> m;
    nums.clear();
    nums.resize(n, vector<int>(m));
    Solution test;
    cout << test.solve() << endl;
  }
}