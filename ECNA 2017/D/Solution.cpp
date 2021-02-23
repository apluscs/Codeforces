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

int n, K;
struct Solution {
  int x = 0;
  stack<int> st;
  Solution() {
    st.push(0);  // first child
  }
  void pass(int t) {
    t = (t % n + n) % n;
    x = (x + t) % n;  // x = top of stack
    st.push(x);
  }
  void undo(int t) {
    while(t--) {
      st.pop();
    }
    x = st.top();
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> K;
  string temp;
  Solution test;
  int m;
  REP(i, K) {
    cin >> temp;
    if (temp == "undo") {
      cin >> m;
      test.undo(m);
    } else {
      test.pass(stoi(temp));
    }
  }
  cout << test.x << endl;
}