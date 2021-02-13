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

int n, k, mod = 998244353;

struct Solution {
  int solve() {
    ll res = 0;
    for (int i = 1; i != n + 1; ++i) {
      int count = n / i;
      if (count < k) continue;
      res += (((fact(count - 1) * power(fact(k - 1), mod - 2)) % mod) *
              power(fact(count - k), mod - 2)) %
             mod;
      res %= mod;
    }
    return res;
  }

  ll power(ll x, ll y) {  // x to y'th power, all modded
    ll t = 1;
    while (y != 0) {
      if (y % 2 == 1) t = t * x % mod;
      x = x * x % mod;
      y /= 2;
    }
    return t;
  }

  ll fact(int x) {  // factorial of x, all modded
    ll res = 1;
    while (x) res = (res * x--) % mod;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  Solution test;
  cout << test.solve() << endl;
}