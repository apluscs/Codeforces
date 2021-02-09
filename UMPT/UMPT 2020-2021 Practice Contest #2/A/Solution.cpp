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
struct Solution {
    vector<int> solve() {
        vector<int> res;
        int base=1;
        while(n){
            int curr=base*(n%10);
            n/=10;
            base*=10;
            if(curr) res.push_back(curr);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    Solution test;
    while (T--) {
        cin >> n;
        auto res=test.solve();
        cout<<res.size()<<endl;
        for(auto r:res)cout<<r<<" ";
        cout<<endl;
    }
}