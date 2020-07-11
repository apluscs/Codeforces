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
  string solve() {
    k++;
    string res = "*";
    for (int last = 0; last != 10; ++last) {
      int ends = 0;
      for (int i = 0; i != k; ++i) {
        ends += (last + i) % 10;
      }
      if (ends > n) continue;
      if (last + k > 10) {
        res = deci_min(res, overflowed(last, ends));
      } else if ((n - ends) % k == 0) {
        string curr = get((n - ends) / k) + to_string(last);
        res = deci_min(res, curr);
      }
    }
    if (res == "*") return "-1";
    return res;
  }

  // |--prefix--||nd||--all 9's||last digit|
  string overflowed(int last, int ends) {
    int count = 0;
    string res = "*";
    while (true) {
      int s = 9 * count * (10 - last);  // all the nums < 10
      if (s > n - ends) break;
      for (int nd = 0; nd != 9; ++nd) {
        // nd applies to the ones < 10, the ones above have nd+1 (the 1 carried
        // over)
        int ns = s + (10 - last) * nd + (k - (10 - last)) * (nd + 1);
        if (ns > n - ends) break;
        if ((n - ns - ends) % k == 0) {
          string curr = get((n - ns - ends) / k);
          // In case nd == 0 and curr == 0, then skip both
          if (curr != "" || nd) curr += to_string(nd);
          for (int i = 0; i != count; ++i) curr += '9';
          curr += to_string(last);
          res = deci_min(res, curr);
        }
      }
      count++;
    }
    return res;
  }

  string get(int target) {  // fill as many with 9's and the rest is target % 9
    string res = target % 9 ? to_string(target % 9) : "";
    target /= 9;
    for (; target; --target) res += '9';
    return res;
  }

  string deci_min(string a, string b) {
    if (a == "*") return b;
    if (b == "*") return a;
    if (a.length() != b.length()) return a.length() < b.length() ? a : b;
    for (int i = 0; i != a.length(); ++i) {
      if (a[i] != b[i]) return a[i] < b[i] ? a : b;
    }
    return a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    Solution test;
    cout << test.solve() << endl;
  }
}