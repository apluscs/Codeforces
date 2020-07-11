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
vector<int> a, b;

struct Solution {
  string solve() {
    vector<int> right(n, 0);
    vector<int> x(n, 0);  // x[i] = what Pi took
    for (int i = 0; i != n; ++i) {
      // min(what RHS offers, what you need from them)
      int took_right = max(0, min(b[i], a[i] - x[i]));
      x[i] += took_right;
      b[i] -= took_right;
      right[i] = took_right;
      // what remains from RHS is now right neighbor's LHS supply
      x[(i + 1) % n] += b[i];
    }
    // now P0 has everything they need from its RHS and what P(N-1) had left
    // over from his RHS. P0 has too much! Need to adjust by reeling in some of
    // what he took from his RHS, and giving it back to his right neighbor.

    for (int i = 0; i != n; ++i) {
      // min(capacity of what you can give back to right neighbor,
      //     how much you can afford to give back (your surplus, if any) )
      int give_right = max(0, min(right[i], x[i] - a[i]));
      x[i] -= give_right;
      x[(i + 1) % n] += give_right;
    }

    for (int i = 0; i != n; ++i) {
      if (x[i] < a[i]) return "NO";
    }

    return "YES";
  }

  void print(vector<int>& v) {
    for (auto num : v) cout << num << " ";
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i != n; ++i) cin >> a[i];
    for (int i = 0; i != n; ++i) cin >> b[i];
    Solution test;
    cout << test.solve() << endl;
  }
}