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

int n, k;

struct Solution {
  void solve() {
    int pairs = n / 2;
    if (n == 1 && k == 0) {
      cout << "1" << endl;
      return;
    }
    if (pairs > k || n == 1) {
      cout << "-1" << endl;  // going to exceed
      return;
    }
    pairs = (n - 2) / 2;
    int rem = k - pairs, odd = 1;
    cout << rem << " " << rem * 2 << " ";
    for (int i = 2; i + 1 < n; i += 2) {
      int even = odd + 1;
      while (rem == even || rem * 2 == even || rem == odd) {
        odd += 2;
        even = odd + 1;
      }
      cout << even << " " << odd << " ";
      odd += 2;
    }
    if (odd == rem) odd += 2;
    if (n & 1) cout << odd;
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  Solution test;
  test.solve();
}