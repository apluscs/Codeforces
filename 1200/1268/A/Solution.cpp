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

using namespace std;

int n, k;
string s;
struct Solution {
  void solve() {
    string pattern;
    cout << n << endl;
    string curr = get_full(s.substr(0, k));
    if (!deci_less(curr, s)) {
      cout << curr << endl;
      return;
    }  // now something needs to change
    for (int i = k - 1; i != -1; --i) {
      if (s[i] != '9') {
        pattern = s.substr(0, k);
        pattern[i]++;
        for (int j = i + 1; j != k; ++j) pattern[j] = '0';
        break;
      }
    }
    cout << get_full(pattern) << endl;
  }
  string get_full(string pat) {
    string res = "";
    for (int i = 0; i != n / k; ++i) res += pat;
    res += pat.substr(0, n % k);
    return res;
  }
  bool deci_less(string a, string b) {  // if a < b
    if (a.length() != b.length()) return a.length() < b.length();
    for (int i = 0; i != a.length(); ++i) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> s;
  Solution test;
  test.solve();
}
