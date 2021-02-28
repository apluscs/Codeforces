#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
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

int nums[4];
vector<pair<int, int>> pairs[10] = {{},{{0, 1}}, {{0, 2}}, {{1, 2}}, {{1, 3}}, {{2, 3}}, {{0, 1}, {0, 2}}, {{0, 1}, {2, 3}}, {{1, 2}, {1, 3}}, {{1, 3}, {2, 3}}};
vector<int> inds = {0, 1, 2, 3};
struct Solution {
  vector<vector<int>> perms;
  string ops_str = "+-*/";
  string solve() {
    int res = INT_MAX;
    do {
      int invs = 0;
      // print(inds);
      REP(o, 64) {
        string ops;
        int x = o, invs = count_invs(inds) * 2;
        REP(i, 3) {
          ops += ops_str[x % 4];
          x /= 4;
        }
        for (auto prs : pairs) {
          int curr = eval(inds, ops, prs) + invs + int(prs.size());
          res = min(res, curr);
        }
        // cout << curr << " ";
      }
    } while (next_permutation(inds.begin(), inds.end()));
    return res >= 100 ? "impossible" : to_string(res);
  }
  int count_invs(vector<int> A) {
    return (A[1] < A[0]) + (A[3] < A[2]) + (A[2] < A[0]) + (A[3] < A[0]) + (A[2] < A[1]) + (A[3] < A[1]);  // simulate merge sort
  }
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }

  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
  string make(vector<int> inds, string ops, vector<pair<int, int>>& prs) {
    string s;
    REP(i, 4) {
      for (auto p : prs)
        if (p.first == i) s += "(";
      s += to_string(nums[inds[i]]);
      for (auto p : prs)
        if (p.second == i) s += ")";
      if (i != 4) s += ops[i];
    }
    return s;
  }
  int eval(vector<int> perm, string ops, vector<pair<int, int>> prs) {
    int res = calculate(make(perm, ops, prs));
    return res == 24 ? 0 : 100;
  }
  int calculate(string s) {
    // cout << s << endl;
    stack<long> st;
    long sum = 0, op1 = 1, prod = 1, op2 = 1, num = 0, n = s.length();  // op2 = 1 means *, 0 means /
    for (int i = 0; i != n; ++i) {
      char c = s[i];
      if (isdigit(c)) {
        while (i != n && isdigit(s[i])) {
          num = num * 10 + s[i++] - '0';
        }                                              // otherwise not a digit, must chain num to current prod
        if (!op2 && (!num || prod % num)) return 100;  // invalid
        prod = op2 ? prod * num : prod / num;
        num = 0;
        i--;
      } else if (c == '*' || c == '/') {
        op2 = c == '*';
      } else if (c == '+' || c == '-') {
        sum += op1 * prod;
        // printf("sum=%d\n",sum);
        op2 = 1;  // only multiplying from now on
        op1 = c == '+' ? 1 : -1, prod = 1;
      } else if (c == '(') {  // first must save everything to stack and reset for helper call
        st.push(sum);
        st.push(op1);
        st.push(prod);
        st.push(op2);
        sum = 0, op1 = 1, prod = 1, op2 = 1;
      } else if (c == ')') {
        int res = sum + op1 * prod;
        op2 = st.top();
        st.pop();
        prod = st.top();
        st.pop();
        op1 = st.top();
        st.pop();
        sum = st.top();
        st.pop();
        if (!op2 && (!res || prod % res)) return 100;  // invalid
        prod = op2 ? prod * res : prod / res;
      }
      // printf("prod=%d\n",prod);
    }
    return sum + op1 * prod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // clock_t tStart = clock();
  REP(i, 4)
  cin >> nums[i];
  Solution test;
  cout << test.solve() << endl;
  // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}