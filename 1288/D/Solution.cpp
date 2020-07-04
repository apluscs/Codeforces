#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define ll long long

using namespace std;

int n, m;
vector<vector<int>> nums;

struct Solution {
  string solve() {
    int low = 0, high = 1e9;
    while (low <= high) {
      int mid = ((ll)low + high) / 2;
      // cout<<mid<<",";
      auto p = able(mid);
      if (p.first != -1)
        low = mid + 1;
      else
        high = mid - 1;
    }
    auto p = able(high);
    return to_string(p.first) + " " + to_string(p.second);
  }

  pair<int, int> able(int k) { // if x is possible
    vector<int> bs(1 << m, -1);
    for (int i = 0; i != n; ++i) {
      bitset<8> bits;
      for (int j = 0; j != m; ++j) {
        bits[j] = nums[i][j] >= k;
      }
      bs[int(bits.to_ulong())] = i;
    }
    for (int i = 0; i != 1 << m; ++i) {
      for (int j = i; j != 1 << m; ++j) {
        if (bs[i] == -1 || bs[j] == -1)
          continue; // no array for one/both of these
        if ((i | j) == (1 << m) - 1)
          return make_pair(bs[i] + 1, 1 + bs[j]);
      }
    }
    return make_pair(-1, -1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  nums = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      cin >> nums[i][j];
    }
  }
  Solution test;
  cout << test.solve() << endl;
}