#include <assert.h>
#include <math.h>

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

int n;

struct Solution {
  int x, y, mx = 0, my = 0;

  void solve() {
    char op;
    while (n--) {
      cin >> op >> x >> y;
      if (x > y) {
        swap(x, y);
      }
      if (op == '?') {
        judge(x, y);
        continue;
      }
      mx = max(x, mx);
      my = max(y, my);
    }
  }

  void judge(int x, int y) {
    // printf("mx=%d, my=%d, x=%d, y=%d\n", mx, my, x, y);
    if (x >= mx && y >= my)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  test.solve();
}