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
     
    int n, p, T;
    vector<vector<int>> judges, tars, feathers;
    struct Solution {
        struct Pair {
            double dist;
            int ju, s;
            Pair(double dist, int ju, int s) : dist(dist), ju(ju), s(s) {}
        };
        struct compar {
            bool operator()(const Pair& a, const Pair& b) const {
                return a.dist != b.dist ? b.dist < a.dist : a.ju != b.ju ? b.ju < a.ju : b.s < a.s;
            }
        };
        double solve() {
            return helper(tars) + helper(feathers);
        }
     
        double helper(vector<vector<int>>& nums) {
            double res = 0;
            int m = nums.size();
            priority_queue<Pair, vector<Pair>, compar> pq;
            for (int i = 0; i != n; ++i) {      // judge index
                for (int j = 0; j != m; ++j) {  // tar index
                    double x = get_dist(judges[i][0], judges[i][1], nums[j][0], nums[j][1]);
                    pq.push(Pair(x, i, j));
                }
            }
            vector<bool> assigned_tars(m), assigned_judges(n);
            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                double dist = p.dist;
                int ju = p.ju, s = p.s;
                if (assigned_tars[s] || assigned_judges[ju]) continue;
                assigned_tars[s] = true;
                assigned_judges[ju] = true;
                res += dist;
            }
            return res;
        }
     
        double get_dist(double x1, double y1, double x2, double y2) {
            return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
    };
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        std::cout << std::fixed;
        std::cout << std::setprecision(6);
        cin >> n >> T >> p;
        judges.resize(n, {0, 0});
        tars.resize(T, {0, 0});
        feathers.resize(p, {0, 0});
        for (int i = 0; i != n; ++i) {
            cin >> judges[i][0] >> judges[i][1];
        }
        for (int i = 0; i != T; ++i) {
            cin >> tars[i][0] >> tars[i][1];
        }
        for (int i = 0; i != p; ++i) {
            cin >> feathers[i][0] >> feathers[i][1];
        }
        Solution test;
        auto res = test.solve();
        cout << res << endl;
    }