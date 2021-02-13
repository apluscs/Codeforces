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

ll l, r, k;

struct Solution {
  void solve() {
    bool found = false;
    double high = pow(10.0, 18);
    for (ll curr = 1; curr <= r;) {
      if (curr >= l) {
        found = true;
        cout << curr << " ";
      }
      if (double(curr) * k > high) {
        break;
      }
      curr *= k;
    }
    if (!found) cout << "-1" << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> l >> r >> k;
  Solution test;
  test.solve();
}