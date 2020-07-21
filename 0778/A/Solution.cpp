#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;

int n, m;
string t, p;
vector<int> nums;

struct Solution {
  void solve() {
    int low = 0, high = n;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (able(mid))
        low = mid + 1;
      else
        high = mid - 1;
    }
    cout << high << endl;
  }
  bool able(int x) {  // is p a subseq of t with the first x removed?
    unordered_set<int> gone;
    for (int i = 0; i != x; ++i) {
      gone.insert(nums[i]);
    }
    int j = 0;  // the next one we want
    for (int i = 0; i != n && j != m; ++i) {
      if (gone.count(i)) continue;
      if (t[i] == p[j]) {
        j++;
      }
    }
    // printf("x= %d, able= %d\n", x, j);
    return j == m;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t >> p;
  n = t.length(), m = p.length();
  nums.resize(n);
  for (int i = 0; i != n; ++i) {
    cin >> nums[i];
    nums[i]--;
  }
  Solution test;
  test.solve();
}