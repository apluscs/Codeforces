#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, k;
vector<int> groups;

struct Solution {
  int solve() {
    int low = 1, high = accumulate(groups.begin(), groups.end(), 0);
    while (low <= high) {
      int mid = (low + high) / 2;
      if (!able(mid)) {
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return low;
  }
  bool able(int cap) {
    int curr = 0, used = 0;
    for (int i = 0; i != n; ++i) {
      if (curr + groups[i] > cap) {
        used++;
        curr = 0;
      }
      curr += groups[i];
    }
    if (curr) used++;  // for last batch of kids
    return used <= k;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  groups.resize(n);
  for (int i = 0; i != n; ++i) {
    cin >> groups[i];
  }
  Solution test;
  cout << test.solve();
}