#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int h, c, t;

struct Solution {
  int solve() {
    if (t <= (h + c) / 2) return 2;
    double k = (t - h) / (h + c - 2 * t), t1 = get_temp(k),
           t2 = get_temp(k + 1);

    if (abs(t1 - t) <= abs(t2 - t)) return 2 * k + 1;
    return 2 * (k + 1) + 1;
  }

  double get_temp(double k) { return ((k + 1) * h + k * c) / (2 * k + 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int tt = 1; tt != T + 1; ++tt) {
    cin >> h >> c >> t;
    Solution test;
    cout << test.solve() << endl;
  }
}