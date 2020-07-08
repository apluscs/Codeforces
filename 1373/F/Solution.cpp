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
    vector<int> gave(n, 0);
    vector<int> x(n, 0);
    for (int i = 0; i < n; i++) {
      int give = max(0, min(b[i], a[i] - x[i]));
      x[i] += give;
      b[i] -= give;
      gave[i] = give;
      x[(i + 1) % n] += b[i];
    }
    print(x);
    print(gave);
    for (int i = 0; i < n; i++) {
      int toShift = max(0, min(gave[i], x[i] - a[i]));
      x[i] -= toShift;
      x[(i + 1) % n] += toShift;
    }
    print(x);

    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (x[i] < a[i]) {
        ok = false;
        break;
      }
    }

    return ok ? "YES" : "NO";
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