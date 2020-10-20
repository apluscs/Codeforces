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

int n;
vector<int> nums;
struct Solution {
    int solve() {
        if (precheck()) return 0;
        int res = 0;
        for (int i = 0, j; i != n; ++i) {
            if (nums[i] % 2 == 0) continue;
            for (j = i; j != n && nums[j] % 2; ++j)
                ;  // now j=first invalid one
            int m = j - i;
            res += m / 2;
            if (m % 2) res += 2;
            i = j - 1;
        }
        return res;
    }
    bool precheck() {
        int res = nums[0];
        for (int num : nums) {
            res = __gcd(res, num);
            // printf("num%d, res=%d\n", num, res);
            if (res == 1) return false;
        }
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    cin >> n;
    nums.resize(n);
    for (int i = 0; i != n; ++i) {
        cin >> nums[i];
    }
    Solution test;
    auto res = test.solve();
    cout << "YES" << endl;
    cout << res << endl;
}