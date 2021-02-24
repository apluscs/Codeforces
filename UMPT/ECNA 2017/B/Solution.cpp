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
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()

using namespace std;
const int mod = 1e9 + 7;

int r, m;  // target, hole
struct Solution {
  int solve() {
    if (r == m) return 1;
    int res = 2, curr = 1;
    vector<bool> vis(2e8 + 1);
    vis[r] = true;
    vector<int> nums;
    nums.pb(r);
    while (res <= 1e4) {  // r stores last one in sequence
      // printf("curr=%d, r=%d\n", curr, r);
      while (vis[curr]) curr++;
      vis[curr] = true;

      r += curr;
      vis[r] = true;
      for (int i = 0; i < nums.size(); ++i) {
        int d = r - nums[i];
        vis[d] = true;
      }
      nums.pb(r);
      if (vis[m]) return res;
      res++;
    }
    return -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> r >> m;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}