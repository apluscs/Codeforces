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

int n;
struct Solution {
  void solve() {
    if (n <= 3) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES\n";
    if (n % 2) {
      cout << "5 - 2 = 3\n3 - 1 = 2\n3 * 4 = 12\n2 * 12 = 24\n";
    } else
      cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    for (int i = n % 2 ? 6 : 5; i < n; i += 2) {
      cout << i + 1 << " - " << i << " = 1\n24 * 1 = 24\n";
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  test.solve();
  cout << flush;
}