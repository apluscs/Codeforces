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

string s;
struct Solution {
  int n;
  int dp[10][10][10][10] = {{{{}}}};
  void solve() {
    n = s.length();
    int frq[10][10] = {{}};
    std::fill(&dp[0][0][0][0],
              &dp[0][0][0][0] + sizeof(dp) / sizeof(dp[0][0][0][0]), -1);
    precompute();
    for (int i = 0; i != n - 1; ++i) {
      frq[s[i] - '0'][s[i + 1] - '0']++; // count frq of adj elems
    }
    for (int i = 0; i != 10; ++i) {
      for (int j = 0; j != 10; ++j) {
        int res = 0;
        for (int c = 0; c != 10 && res != -1; ++c) {
          for (int d = 0; d != 10 && res != -1; ++d) {
            if (frq[c][d] == 0)
              continue;
            int v = dp[i][j][c][d];
            res = v == -1 ? -1 : res + frq[c][d] * (v - 1);
          }
        }
        cout << res << " ";
      }
      cout << endl;
    }
  }
  void precompute() {
    for (int i = 0; i != 10; ++i) {
      for (int j = 0; j != 10; ++j) {
        for (int c = 0; c != 10; ++c) { // starting value
          for (int ci = 0; ci != 10; ++ci) {
            for (int cj = 0; cj != 10; ++cj) {
              if (ci == 0 && cj == 0) // cannot go from yourself to yourself in 0 moves
                continue;
              int d = (ci * i + cj * j + c) % 10;
              int &curr = dp[i][j][c][d], cand = ci + cj;
              if (curr == -1 || cand <= curr) {
                curr = cand;
              }
            }
          }
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> s;
    Solution test;
    test.solve();
  }
}
