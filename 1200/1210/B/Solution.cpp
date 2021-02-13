#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<ll> a, b;
struct Solution {
  void solve() {
    vector<bool> safe(n);
    for (int i = 0; i != n; ++i) {
      for (int j = i + 1; j != n; ++j) {
        if (a[i] == a[j]) {
          safe[i] = safe[j] = true;
          break;
        }
      }
    }
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != n; ++j) {
        if (!safe[j] || i == j)
          continue;
        if ((a[i] | a[j]) == a[j]) {
          safe[i] = true;
        }
      }
    }
    ll res = 0;
    for (int i = 0; i != n; ++i) {
      if (safe[i])
        res += b[i];
    }
    cout << res << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i != n; ++i)
      cin >> a[i];
    for (int i = 0; i != n; ++i)
      cin >> b[i];
    Solution test;
    test.solve();
  }
}
