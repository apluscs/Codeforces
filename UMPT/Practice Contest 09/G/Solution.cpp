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

int n, m, A[201], B[201], K = 1 << 9;
struct Solution {
  int solve() {
    vector<bool> dp(K);
    int res = K;
    dp[0] = true;
    REP(i, n) {
      vector<bool> next(K);
      // printf("i=%d\n", i);
      REP(j, m) {
        int x = A[i] & B[j];
        for (int p = 0; p != K; ++p)
          if (dp[p]) {
            next[p | x] = true;
            // printf("p=%d, x=%d, i=%d, j=%d\n", p, x,A[i],B[j]);
          }
      }
      dp = next;
    }
    REP(j, K) {
      if (dp[j]) res = min(res, j);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, n)
  cin >> A[i];
  REP(i, m)
  cin >> B[i];
  Solution test;
  cout << test.solve() << endl;
}