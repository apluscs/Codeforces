#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<int> nums;
struct Solution {
    int solve() {
        unordered_set<int> us(nums.begin(),nums.end());
        if(us.count(0)) us.erase(us.find(0));
        return us.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    nums.resize(n);
    for (int i = 0; i != n; ++i) {
        cin >> nums[i];
    }
    Solution test;
    cout << test.solve() << endl;
}