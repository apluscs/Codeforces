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

int n;
ll HIGH = 1LL << 32;
struct Solution {
  string solve() {
    string type;
    int x;
    ll res = 0, curr = 1;
    stack<ll> st;
    st.push(1);
    REP(i, n) {
      cin >> type;
      if (type == "add") {
        res += st.top();
      } else if (type == "for") {
        cin >> x;
        st.push(min(HIGH, x * st.top()));  // if not used, won't be inaccurate; if used once, will be caught
      } else {                             // end
        st.pop();
      }
      if (res >= HIGH) return "OVERFLOW!!!";
      // printf("curr=%d, res=%d, type=%s\n", curr, res, type.c_str());
    }
    return to_string(res);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  cout << test.solve() << endl;
}