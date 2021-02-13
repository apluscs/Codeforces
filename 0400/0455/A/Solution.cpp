#include <assert.h>

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
vector<int> frq(1e5 + 5);
struct Solution {
  ll solve() {
    vector<ll> dp(1e5 + 5);
    for (ll i = 2; i <= 1e5 + 1; ++i) {
      dp[i] = max(dp[i - 1], (i - 1) * frq[i - 1] + dp[i - 2]);
    }
    return dp[1e5 + 1];
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  fill(frq.begin(), frq.end(), 0);
  for (int i = 0, x; i != n; ++i) {
    cin >> x;
    frq[x]++;
  }
  Solution test;
  cout << test.solve() << endl;
}