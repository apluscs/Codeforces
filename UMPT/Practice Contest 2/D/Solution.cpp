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

int n, m, a, b;
vector<int> avgs;
struct Solution {
    ll solve(int s, int e) {
        ll count = prefix(e) - prefix(s - 1);
        if(s==e){
            if(*lower_bound(avgs.begin(),avgs.end(),s)==s)return count*b; // there is >= 1 avenger here
            else return a;
        }
        if (count <= 0) {
            // printf("s=%d, e=%d, a=%d\n", s, e, a);
            return a;  // no avengers here
        }
        ll res = count * b * (e - s + 1);  // destroy directly
        int mid = (s + e) / 2;
        res = min(res, solve(s, mid) + solve(mid + 1, e));
        // printf("s=%d, e=%d, res=%lld\n", s, e, res);
        return res;
    }
    int prefix(int pos) {
        if (pos < avgs[0]) return 0;
        int res = upper_bound(avgs.begin(), avgs.end(), pos) - avgs.begin();
        // printf("pos%d, res=%d\n", pos, res);
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    avgs.resize(m);
    for (int i = 0; i != m; ++i) {
        cin >> avgs[i];
    }
    Solution test;
    sort(avgs.begin(), avgs.end());
    // for(auto a:avgs)cout<<a<<" ";
    auto res = test.solve(1, (1 << n));
    cout << res << endl;
}