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

int n, k, x;
vector<int> nums;
struct Solution {
  void solve() {
    ll m = 1;
    while (k--)
      m *= x;
    // cout << m << endl;
    vector<ll> pre(n), suf(n + 1);
    for (int i = 0; i != n; ++i) {
      pre[i] = (i == 0 ? 0 : pre[i - 1]) | nums[i];
      suf[n - i - 1] = suf[n - i] | nums[n - i - 1];
    }
    // for(auto p:pre)cout<<p<<" ";cout<<endl;
    // for(auto p:suf)cout<<p<<" ";cout<<endl;
    ll res = 0;
    for (int i = 0; i != n; ++i) {
      res = max(res, m * nums[i] | (i == 0 ? 0 : pre[i - 1]) | suf[i + 1]);
    }
    cout << res << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n >> k >> x;
    nums.resize(n);
    for (int i = 0; i != n; ++i)
      cin >> nums[i];
    Solution test;
    test.solve();
  }
}
