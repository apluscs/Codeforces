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

int n;
vector<int> nums;

struct Solution {
  vector<int> minDiv;
  void solve() {
    prework();
    vector<int> d1(n), d2(n);
    for (int i = 0; i != n; ++i) {
      auto fac = get_factors(nums[i]);
      if (fac.size() == 1) {
        d1[i] = d2[i] = -1;
        continue;
      }
      d1[i] = fac[0];
      int x = 1;
      for (int j = 1; j < fac.size(); ++j) {
        x *= fac[j];
      }
      d2[i] = x;
    }
    for (auto d : d1) cout << d << " ";
    cout << endl;
    for (auto d : d2) cout << d << " ";
    cout << endl;
  }

  vector<int> get_factors(int x) {
    vector<int> res;
    while (x > 1) {
      int p = minDiv[x];
      while (x % p == 0) x /= p;
      res.push_back(p);
    }
    return res;
  }

  void prework() {
    minDiv.resize(1e7 + 1);
    iota(minDiv.begin(), minDiv.end(), 0);  // initial starts off as value
    for (int i = 2; i != minDiv.size(); ++i) {
      if (minDiv[i] != i) continue;  // not prime
      for (ll j = (ll)i * i; j < minDiv.size(); j += i) {
        minDiv[j] = min(i, minDiv[j]);
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  nums.resize(n);
  for (int i = 0; i != n; ++i) cin >> nums[i];
  Solution test;
  test.solve();
}