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

int a, b, c, d, e, f, g;
struct Solution {
    int solve() {
        auto vols = get_vols();
        auto first=get_all(vols[0], c), second=get_all(vols[1],d), third=get_all(vols[2],e);
        for(auto x:first){
            if(second.count(x) && third.count(x))return x;
        }
        return -1;
    }
    unordered_set<int> get_all(int v, int r){
        int curr=r;
        unordered_set<int>res;
        while(curr<= g){
            if(curr>=f){
                res.insert(curr);
            }
            curr+=v;
        }
        return res;
    }
    vector<int> get_vols() {
        vector<int> res;
        for (int x = 1; 2 * x < a; x++) {  // side of square length
            int curr = x * (a - 2 * x) * (b - 2 * x);
            res.push_back(curr);
        }
        sort(res.begin(), res.end());
        // for (auto v : res) cout << v << " ";
        // return res;
        return vector<int>(res.rbegin(), res.rbegin()+3);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f >> g;
    Solution test;
    auto res = test.solve();
    cout << res << endl;
}