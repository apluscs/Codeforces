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

int c, m, x;
struct Solution {
  int solve() {
    int b = min(c, m);
    c -= b, m -= b;  // ideally, but do we have enough 'others'?
    int others = c + m + x;
    // printf("b=%d, others=%d\n", b, others);
    if (b < others) return b;  // not enough cores
    return b - (b - others + 2) / 3;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q;
  cin >> Q;
  Solution test;
  while (Q--) {
    cin >> c >> m >> x;
    // if (i == 26) {
    //   printf("c=%d, m=%d, x=%d\n", c, m, x);
    // }
    cout << test.solve() << endl;
  }
}