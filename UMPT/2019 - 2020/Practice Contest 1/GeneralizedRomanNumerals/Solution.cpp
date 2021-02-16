#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n;
string str;

struct Solution {
  vector<vector<unordered_set<int>>> dp;
  unordered_map<char, int> m;
  Solution() {
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
  }
  vector<int> solve() {
    dp.resize(n, vector<unordered_set<int>>(n));
    auto x = help(0, n - 1);
    vector<int> res(x.begin(), x.end());
    sort(res.begin(), res.end());
    return res;
  }

  unordered_set<int> help(int s, int e) {
    if (s > e) return {};
    if (s == e) return {m[str[s]]};
    if (!dp[s][e].empty()) return dp[s][e];
    unordered_set<int> res;
    for (int m = s; m != e; ++m) {  // m=last one of section one
      auto a = help(s, m), b = help(m + 1, e);
      for (auto x : a) {
        for (auto y : b) {
          if (x < y)
            res.insert(y - x);
          else
            res.insert(x + y);
        }
      }
    }
    // cout << "s=" << s << ",e=" << e << endl;
    // for (auto x : res) {
    //   cout << x << " ";
    // }
    // cout << endl;
    dp[s][e] = res;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);

  for (int c = 1; true; ++c) {
    Solution test;
    cin >> str;
    if (str == "0") break;
    n = str.length();
    auto res = test.solve();
    cout << "Case " << c << ": ";
    for (auto x : res) {
      cout << x << " ";
    }
    cout << endl;
  }
}