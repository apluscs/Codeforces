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

int n, m, rices, k;
vector<string> ss;

struct Solution {
  void solve() {
    vector<string> res = ss;
    int curr = 0;
    char c = 'a';
    for (int i = 0, ckn = 0; i != n; ++i) {
      for (int x = 0; x != m; ++x) {
        int j = i % 2 ? m - x - 1 : x;
        curr += ss[i][j] == 'R';
        res[i][j] = c;
        if (ckn < rices % k && curr == rices / k + 1 ||
            ckn >= rices % k && curr == rices / k) {
          ckn++;
          curr = 0;
          c = ckn == k ? c : next_char(c);
        }
      }
    }
    for (int i = 0; i != n; ++i) cout << res[i] << endl;
    // cout << endl;
  }
  char next_char(char c) {
    if (c == 'z') return 'A';
    if (c == 'Z') return '0';
    return c + 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    rices = 0;
    ss.resize(n);
    for (int i = 0; i != n; ++i) {
      cin >> ss[i];
      for (int j = 0; j != m; ++j) {
        rices += ss[i][j] == 'R';
      }
    }
    Solution test;
    test.solve();
  }
}
