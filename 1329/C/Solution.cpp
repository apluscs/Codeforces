#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, k, n) for (ll i = k; i < n; i++)
#define repr_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define ll long long

using namespace std;
const int mod=1e9+7;

int d,m;
struct Solution {
  ll solve() {
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t != T + 1; ++t) {
    cin >> d>>m;
    Solution test;
    cout << test.solve() << endl;
  }
}