#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n;
vector<vector<int>> b;

struct Solution {
  string solve() {
    vector<int> res(n);
    for (int i = 0; i != n; ++i) {
      int curr = 0;
      for (int j = 0; j != n; ++j) {
        if (j == i) continue;
        curr |= b[i][j];
      }
      res[i] = curr;
    }
    string s = "";
    for (auto r : res) s += to_string(r) + " ";
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  b.clear();
  b.resize(n, vector<int>(n));
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      cin >> b[i][j];
    }
  }
  Solution test;
  cout << test.solve() << endl;
}