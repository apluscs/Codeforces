#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, m;

struct Solution {
  string solve() {  // sliding
    string s;
    vector<int> times;
    int start = 0;
    getline(cin, s);  // discard the \n
    while (getline(cin, s)) {
      int month = stoi(s.substr(5, 2));
      int day = stoi(s.substr(8, 2));
      int hour = stoi(s.substr(11, 2));
      int min = stoi(s.substr(14, 2));
      int second = stoi(s.substr(17, 2));
      int sec = second + min * 60 + hour * 3600 + day * 24 * 3600;
      for (int i = 0; i + 1 < month; i++) sec += months[i] * 24 * 3600;
      while (start < times.size() && times[start] + n <= sec) start++;
      times.push_back(sec);
      if (times.size() - start >= m) {
        return s.substr(0, 19);
      }
    }
    return "-1";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  Solution test;
  cout << test.solve() << endl;
}