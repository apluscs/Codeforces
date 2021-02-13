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
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;

int n;
vector<int> nums(n);

struct Solution {
  int solve() {
    int res = 0, i = 1, prev = 1;  // prev = how many nodes in prev layer
    while (i != n) {
      int curr = 0, j;
      while (prev-- && i != n) {
        for (j = i + 1; j != n && nums[j] > nums[j - 1]; ++j)
          ;
        curr += j - i;
        // printf("i=%d, j=%d\n", i, j);
        i = j;
      }
      prev = curr;
      res++;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    nums.resize(n);
    REP(i, n) {
      cin >> nums[i];
    }
    Solution test;
    cout << test.solve() << endl;
  }
}