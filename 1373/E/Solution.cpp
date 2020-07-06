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

int n, m, mod = 998244353;
vector<int> a, b;

struct Solution {
  int solve() {
    ll res = 1;
    int x, y = n - 1;
    for (int i = m - 1; i; --i) {
      x = find_good(y, b[i]);
      y = find_bad(x - 1, b[i]);
      // cout << x << "," << y << endl;
      if (x == -1) return 0;
      res = (res * (x - y)) % mod;
    }
    if (*min_element(a.begin(), a.begin() + y + 1) != b[0]) return 0;
    return res;
  }

  int find_good(int start, int v) {  // first one <= start whose value == v
    for (int i = start, low = INT_MAX; i > -1; --i) {
      low = min(low, a[i]);
      if (low == v) return i;
      if (low < v) return -1;
    }
    return -1;
  }

  int find_bad(int start, int v) {  // first one <= start whose value < v
    for (int i = start, low = INT_MAX; i > -1; --i) {
      low = min(low, a[i]);
      if (low < v) return i;
    }
    return -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  for (int i = 0; i != n; ++i) cin >> a[i];
  for (int i = 0; i != m; ++i) cin >> b[i];
  Solution test;
  cout << test.solve() << endl;
}