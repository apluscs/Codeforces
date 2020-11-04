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
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<int> nums;
struct Solution {
  vector<int> solve() {
    vector<int> res(n);
    REP(i, n) {
      vector<bool> vis(n);
      int j;
      for (j = i; !vis[j]; vis[j] = true, j = nums[j]) {
        // printf("j=%d\n", j);
      }
      res[i] = j + 1;
      // cout << endl;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  REP(i, n) {
    cin >> nums[i];
    nums[i]--;
  }
  Solution test;
  auto res = test.solve();
  for (auto r : res) {
    cout << r << " ";
  }
  cout << endl;
}