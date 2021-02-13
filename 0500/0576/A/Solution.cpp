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

int n;
struct Solution {
  void solve() {
    int res = 0;
    vector<bool> ps(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ps[i]) continue;
      for (int j = i * i; j <= n; j += i) {
        ps[j] = false;
      }
      res++;
      for (int j = i * i; j <= n; j *= i) {
        res++;
      }
    }
    cout << res << endl;
    for (int i = 2; i <= n; ++i) {
      if (!ps[i]) continue;
      cout << i << " ";
      for (int j = i * i; j <= n; j *= i) {
        cout << j << " ";
      }
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  test.solve();
  cout << flush;
}