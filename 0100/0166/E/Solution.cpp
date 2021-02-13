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

int n, mod = 1e9 + 7;

struct Solution {
  int solve() {
    ll d = 1, a = 0;
    for (int i = 0; i != n; ++i) {
      long long temp = d;  // prev d
      d = (a * 3) % mod;
      a = (a * 2 + temp) % mod;
    }
    return d;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  cout << test.solve() << endl;
}