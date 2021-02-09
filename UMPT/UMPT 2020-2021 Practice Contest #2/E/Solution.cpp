#include <assert.h>
#include <float.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iomanip>
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

int n, m, a, c, x0;
vector<int> nums;
struct Solution {
    int solve(int low, int high, int lb, int ub) {  // lb,ub track range of what values are still discoverable
        if (low > high) return 0;                   // malformed array
        int mid = (low + high) / 2;
        if (nums[mid] >= lb && nums[mid] <= ub)
            return 1 + solve(mid + 1, high, nums[mid], ub) + solve(low, mid - 1, lb, nums[mid]);  // bc you wouldn't look for anything < nums[mid] right of mid, only those > nums[mid] are discoverable on RHS; similar logic for LHS (ex. 2 6 10=mid 13 7, lb=1, ub=10 --> wouldn't look for 9 right of mid)
        if (nums[mid] < lb) {
            return solve(mid + 1, high, lb, ub);  // for every discoverable value, you'd go to the right, and all of them are still discoverable (ex. 2 6 10=mid 13 70, lb=50, ub=100 --> wouldn't look for 50 left of mid)
        }
        return solve(low, mid - 1, lb, ub);  // similar logic as case 2
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    cin >> n >> m >> a >> c >> x0;
    nums.resize(n + 1);
    nums[0] = x0;
    for (int i = 1; i <= n; ++i) {
        nums[i] = ((ll)nums[i - 1] * a + c) % m;
    }
    Solution test;
    auto res = test.solve(1, n, 0, INT_MAX);
    cout << res << endl;
}