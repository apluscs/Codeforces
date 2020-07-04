#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define ll long long

using namespace std;

int n, m;
vector<int> times;

struct Solution {
  vector<int> bit;
  int B;
  void update(int i, int v) { // update all the way up to the root
    i++;
    while (i <= B) {
      bit[i] += v;
      i += i & (-i);
    }
  }
  int get(int i) { // sum from i to the start of the array
    int res = 0;
    i++;
    while (i > 0) {
      res += bit[i];
      i -= i & (-i);
    }
    return res;
  }
  string solve() {
    vector<int> mn(n), pos(n);
    iota(mn.begin(), mn.end(), 0); // fills in with original indexes
    vector<int> mx = mn;

    times.resize(m);
    for (int i = 0; i != m; ++i) {
      cin >> times[i];
      times[i]--;
      mn[times[i]] = 0; // was at the top at one point
    }

    B = m + n;
    bit.resize(1 + B);
    for (int i = 0; i != n; ++i) {
      pos[i] = m + i; //
      update(pos[i], 1);
    }

    for (int i = 0; i != m; ++i) {
      int p = times[i];
      mx[p] = max(mx[p], get(pos[p] - 1));
      
      update(pos[p], -1);
      pos[p] = m - i - 1;
      update(pos[p], 1);
    }

    for (int i = 0; i != n; ++i) {
      mx[i] = max(mx[i], get(pos[i] - 1)); // final run through
    }

    string res = "";
    for (int i = 0; i != n; ++i) {
      res += to_string(mn[i] + 1) + " " + to_string(mx[i] + 1) + "\n";
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  Solution test;
  cout << test.solve() << endl;
}