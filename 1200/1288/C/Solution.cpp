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

int n, m, mod = 1e9 + 7;

struct Solution {
  int solve() {
    return (fact(2 * m + n - 1) * power(fact(2 * m), mod - 2))%mod *
           power(fact(n - 1), mod - 2) % mod;
  }
  
  ll power(ll x, ll y) {
    ll t = 1;
    while (y != 0) {
      if (y % 2 == 1) t = t * x % mod;
      x = x * x % mod;
      y /= 2;
    }
    return t;
  }

  ll fact(int x) {
    ll res = 1;
    while (x)
      res = (res * x--) % mod;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  Solution test;
  cout << test.solve() << endl;
}