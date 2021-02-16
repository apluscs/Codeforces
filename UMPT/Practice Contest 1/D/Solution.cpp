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

int n, m;
vector<ll> counts, queries;
struct Solution {
    vector<vector<ll>> solve() {
        vector<ll> prefix(n);
        vector<vector<ll>> res;
        prefix.resize(n + 1);
        for (int i = 1; i != n + 1; ++i) {
            prefix[i] = counts[i - 1] + prefix[i - 1];
        }
        for (int i = 0; i != m; ++i) {
            ll q = queries[i], j = lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin(), x = q - prefix[j - 1];
            res.push_back({j, x});
        }
        return res;
    }

    void print(vector<int>& nums) {
        for (auto num : nums) cout << num << " ";
        cout << endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    counts.resize(n);
    queries.resize(m);
    for (int i = 0; i != n; ++i) {
        cin >> counts[i];
    }
    for (int i = 0; i != m; ++i) {
        cin >> queries[i];
    }
    Solution test;
    auto res = test.solve();
    for (auto row : res) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}