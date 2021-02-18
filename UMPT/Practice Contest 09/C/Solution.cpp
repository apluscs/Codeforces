#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n;
struct Solution {
  int solve() {
    int x, h1 = -1, h2 = -1, l1 = INT_MAX, l2 = INT_MAX;
    REP(i, n) {
      cin >> x;
      if (x >= h1)
        h2 = h1, h1 = x;
      else if (x > h2)
        h2 = x;
      if (x <= l1)
        l2 = l1, l1 = x;
      else if (x < l2)
        l2 = x;
    }
    return min(h2 - l1, h1 - l2);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  Solution test;
  cout << test.solve() << endl;
}