#include <assert.h>

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

int n, m = 1e6;
vector<int> frq(m + 5);
struct Solution {
  int solve() {
    int res = 0;
    for (int i = 0; i <= m; ++i) {
      int f = frq[i];
      if (i == m) {
        res += hammingDistance(f);
        continue;
      }
      frq[i + 1] += f / 2;
      if (f % 2) res++;
    }
    return res;
  }
  int hammingDistance(int x) {  // count #ones
    int count = 0;
    for (int i = 0; i < 32; i++)
      if (x & (1 << i)) count++;
    return count;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  fill(frq.begin(), frq.end(), 0);
  for (int i = 0, x; i != n; ++i) {
    cin >> x;
    frq[x]++;
  }
  Solution test;
  cout << test.solve() << endl;
}