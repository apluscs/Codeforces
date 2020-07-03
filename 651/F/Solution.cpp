#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n;

struct Solution {
  int solve() { return res; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  Solution test;
  cout << test.solve() << endl;
}