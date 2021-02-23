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
#include <set>
#include <stack>
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
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

ll ju[10], jr[10], mu[10], mr[10], mt[10];
struct Solution {
  ll solve() {
    ll res = 0;
    REP(round, 3) {
      REP(i, 10) {          // machine Jim uses
        if (mt[i] > res) {  // Jim can use it
          res += ju[i] + jr[i], mt[i] = max(mt[i], res - jr[i]);
          // printf("i=%d, mt[i]=%lld\n", i, mt[i]);
        } else {
          ll span = res - mt[i], period = mr[i] + mu[i], k = span / period;
          mt[i] += k * period;            // last one <= res
          res = max(res, mt[i] + mu[i]);  // must wait for Bob to finish using
          res += ju[i] + jr[i];           // after Bob uses and Jim uses and recovers
          mt[i] = max(res - jr[i], mt[i] + mu[i] + mr[i]);
        }
      }
    }
    return res - jr[9];  // don't need to recover at the end
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  REP(i, 10)
  cin >> ju[i] >> jr[i];
  REP(i, 10)
  cin >> mu[i] >> mr[i] >> mt[i];
  Solution test;
  cout << test.solve() << endl;
}