#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string s;

struct Solution {
  int solve() {
    int curr = 0, res = 0, start = 0;
    for (char c : s) {
      curr += c == '+' ? 1 : -1;
      res = max(res, curr);
      start = min(start, curr);
    }
    return res - start;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  Solution test;
  cout << test.solve() << endl;
}
