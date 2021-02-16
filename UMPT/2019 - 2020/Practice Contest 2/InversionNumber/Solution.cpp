#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

int n;

class Solution {
 public:
  ll solve(vector<int>& nums) { return mergeSort(nums, 0, n - 1); }

  ll mergeSort(vector<int>& nums, int s, int e) {
    if (s >= e) return 0;
    int mid = (s + e) / 2;
    ll a = mergeSort(nums, s, mid), b = mergeSort(nums, mid + 1, e);
    return a + b + merge(nums, s, mid, mid + 1, e);
  }

  ll merge(vector<int>& nums, int s1, int e1, int s2, int e2) {
    int i = s1, j = s2;
    ll res = 0;
    // cout << s1 << ", " << e1 << ", " << s2 << ", " << e2 <<endl;
    vector<int> temp(e2 - s1 + 1);
    while (j <= e2) {
      ll x = nums[j];
      while (i <= e1 && nums[i] <= x) {  // ignore all that aren't inverted
        i++;
      }
      res += e1 - i + 1;
      j++;
    }
    // cout<<res<<endl;
    i = s1;
    j = s2;
    for (int k = 0; k != temp.size(); ++k) {
      if (i > e1)
        temp[k] = nums[j++];
      else if (j > e2)
        temp[k] = nums[i++];
      else if (nums[i] < nums[j])
        temp[k] = nums[i++];
      else
        temp[k] = nums[j++];
      // cout<<k<<endl;
    }

    for (int k = 0; k != temp.size(); ++k) {
      nums[k + s1] = temp[k];
    }

    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i != n; ++i) {
    cin >> nums[i];
  }
  Solution test;
  cout << test.solve(nums) << endl;
}