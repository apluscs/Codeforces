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

string s;
struct Solution {
  void solve() {
    int n = s.length();
    auto f = get_failure(s);
    auto last = f.begin() + n - 1;
    int b = f.back();
    if (!b) {
      cout << "Just a legend" << endl;
      return;
    }
    if (find(f.begin(), last, b) != last) {
      cout << s.substr(0, b) << endl;
      return;
    }
    if (f[b - 1]) {
      cout << s.substr(0, f[b - 1]) << endl;
      return;
    }
    cout << "Just a legend" << endl;
    return;
  }

  vector<int> get_failure(string &str) {
    int m = str.length();
    vector<int> res(m);
    for (int i = 1, j = 0; i != m; ++i) {
      while (j != 0 && str[j] != str[i])
        j = res[j - 1];
      if (str[i] == str[j])
        res[i] = ++j;
    }
    return res;
  }
};

bool all_unique(int x){
    vector<int> frq(10);
    while(x){
        int last = x%10;
        frq[last]++;
        x/=10;
        if(frq[last]==2)return false;
    }
    return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l,r;
  cin>>l>>r;
  for(int i=l;i<=r;++i){
      if(all_unique(i)){
          cout<<i<<endl;
          return 0;
      }
  }
  cout<<-1<<endl;
}