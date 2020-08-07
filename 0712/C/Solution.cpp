#include <assert.h>
#include <math.h>

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

int x, y;

struct Solution {
  int a, b, c; // go backwards
  void solve() {
    int res = 0;
    a = b = c = y;
    while (!satisfied()) {
      int best = min(a, min(b, c)), *best_ref = &a;
      if (best == b)
        best_ref = &b;
      else if (best == c)
        best_ref = &c;
      int sum = a + b + c;
      // doesn't matter how high the highest one climbs. As long as he is at the
      // bar and the second highest is >= 1, bar can be achieved.
      *best_ref = min(sum - *best_ref - 1, x);
      res++;
    }
    cout << res << endl;
  }
  bool satisfied() { return a == x && b == x && c == x; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y;
  Solution test;
  test.solve();
}