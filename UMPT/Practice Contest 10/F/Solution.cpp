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

string s;
int l, r, k;
struct Solution {
  void update() {
    int len = r - l + 1;
    k %= len;
    string x = s.substr(r - k + 1, k) + s.substr(l, len - k);
    s = s.substr(0, l) + x + s.substr(r + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int Q;
  cin >> Q;
  Solution test;
  while (Q--) {
    cin >> l >> r >> k;
    l--, r--;
    test.update();
  }
  cout << s << endl;
}