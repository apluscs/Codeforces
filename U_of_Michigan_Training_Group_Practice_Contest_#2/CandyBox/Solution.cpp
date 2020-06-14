#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, m;

struct Solution {
  int solve() { return __gcd(n, m); }
};

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t != T; ++t) {
    cin >> n >> m;
    Solution test;
    cout << test.solve() << endl;
  }
}